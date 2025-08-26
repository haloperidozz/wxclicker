/*
 * Copyright (C) 2025 haloperidozz
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "mouse/win32/NtUserSendInputBackend.hxx"

#include <cstring>
#include <stdexcept>

namespace wxclicker::mouse::win32 {

NtUserSendInputBackend::NtUserSendInputBackend(bool spoof)
    : _spoof(spoof)
{
    _fnNtUserSendInput = FindNtUserSendInput(spoof);

    if (!_fnNtUserSendInput) {
        throw std::runtime_error("NtUserSendInput not found");
    }
}

NtUserSendInputBackend::~NtUserSendInputBackend()
{
    const auto ptr{reinterpret_cast<LPVOID>(_fnNtUserSendInput)};

    if (_spoof && ptr) {
        ::VirtualFree(ptr, 0, MEM_RELEASE);
    }
}

std::string_view NtUserSendInputBackend::GetName() const noexcept
{
    return _spoof ? "NtUserSendInput (spoofed)" : "NtUserSendInput";
}

void NtUserSendInputBackend::SendMouseInput(const MOUSEINPUT& input) noexcept
{
    INPUT input_{};

    input_.type = INPUT_MOUSE;
    input_.mi   = input;

    _fnNtUserSendInput(1, &input_, sizeof(INPUT));
}

NtUserSendInputBackend::NtUserSendInputType
NtUserSendInputBackend::FindNtUserSendInput(bool spoof) const
{
    constexpr SIZE_T AllocSize{4096}; // 4 KB page
    constexpr SIZE_T CopySize{40};    // 23 bytes on Win11 + safety margin

    FARPROC address{nullptr};

    const auto win32uModule{::GetModuleHandleW(L"win32u.dll")};
    const auto user32Module{::GetModuleHandleW(L"user32.dll")};
    
    if (win32uModule) {
        address = ::GetProcAddress(win32uModule, "NtUserSendInput");
    }

    if (!address && user32Module) {
        address = ::GetProcAddress(user32Module, "NtUserSendInput");
    }

    if (!spoof) {
        return reinterpret_cast<NtUserSendInputType>(address);
    }

    LPVOID spoofed{
        ::VirtualAlloc(0, AllocSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE)
    };

    if (!spoofed) {
        return nullptr;
    }

    std::memcpy(spoofed, reinterpret_cast<LPVOID>(address), CopySize);

    return reinterpret_cast<NtUserSendInputType>(spoofed);
}

} // namespace wxclicker::mouse::win32

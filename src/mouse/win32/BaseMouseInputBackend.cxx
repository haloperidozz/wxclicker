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

#include "mouse/win32/BaseMouseInputBackend.hxx"

namespace wxclicker::mouse::win32 {

void BaseMouseInputBackend::Down(MouseButton button) noexcept
{
    MOUSEINPUT input{};

    switch (button) {
        case MouseButton::Left:
            input.dwFlags = MOUSEEVENTF_LEFTDOWN;
            break;
        case MouseButton::Middle:
            input.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
            break;
        case MouseButton::Right:
            input.dwFlags = MOUSEEVENTF_RIGHTDOWN;
            break;
        default:
            return;
    }

    SendMouseInput(input);
}

void BaseMouseInputBackend::Up(MouseButton button) noexcept
{
    MOUSEINPUT input{};

    switch (button) {
        case MouseButton::Left:
            input.dwFlags = MOUSEEVENTF_LEFTUP;
            break;
        case MouseButton::Middle:
            input.dwFlags = MOUSEEVENTF_MIDDLEUP;
            break;
        case MouseButton::Right:
            input.dwFlags = MOUSEEVENTF_RIGHTUP;
            break;
        default:
            return;
    }

    SendMouseInput(input);
}

void BaseMouseInputBackend::SetPosition(int x, int y) noexcept
{
    MOUSEINPUT input{};

    input.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;

    const auto cxScreen{GetSystemMetrics(SM_CXVIRTUALSCREEN)};
    const auto cyScreen{GetSystemMetrics(SM_CYVIRTUALSCREEN)};

    const auto normX{(static_cast<double>(x) * 65535.0) / (cxScreen - 1)};
    const auto normY{(static_cast<double>(y) * 65535.0) / (cyScreen - 1)};

    input.dx = static_cast<LONG>(normX);
    input.dy = static_cast<LONG>(normY);

    SendMouseInput(input);
}

} // namespace wxclicker::mouse::win32

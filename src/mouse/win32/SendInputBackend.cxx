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

#include "mouse/win32/SendInputBackend.hxx"

namespace wxclicker::mouse::win32 {

std::string_view SendInputBackend::GetName() const noexcept
{
    return "SendInput";
}

void SendInputBackend::SendMouseInput(const MOUSEINPUT& input) noexcept
{
    INPUT input_{};

    input_.type = INPUT_MOUSE;
    input_.mi   = input;

    ::SendInput(1, &input_, sizeof(INPUT));
}

} // namespace wxclicker::mouse::win32

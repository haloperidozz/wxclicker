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

#pragma once

#include <windows.h>

#include "mouse/IMouseInputBackend.hxx"
#include "mouse/MouseButton.hxx"

namespace wxclicker::mouse::win32 {

class BaseMouseInputBackend : public IMouseInputBackend
{
public:
    void Down(MouseButton button) noexcept override final;
    void Up(MouseButton button) noexcept override final;

    void SetPosition(int x, int y) noexcept override final;

protected:
    virtual void SendMouseInput(const MOUSEINPUT& input) noexcept = 0;
};

} // namespace wxclicker::mouse::win32

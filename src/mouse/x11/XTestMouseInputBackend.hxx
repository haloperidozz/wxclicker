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

#include <X11/Xlib.h>

#include "mouse/IMouseInputBackend.hxx"

namespace wxclicker::mouse::x11 {

class XTestMouseInputBackend final : public IMouseInputBackend
{
public:
    XTestMouseInputBackend();
    ~XTestMouseInputBackend();

    std::string_view GetName() const noexcept override;
    
    void Down(MouseButton button) noexcept override;
    void Up(MouseButton button) noexcept override;

    void SetPosition(int x, int y) noexcept override;

private:
    int ToX11ButtonNumber(MouseButton button) const noexcept;

    Display* _display{nullptr};
    Window   _root{};
};

} // namespace wxclicker::mouse::x11

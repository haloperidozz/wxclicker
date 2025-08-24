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

#include "mouse/x11/XTestMouseInputBackend.hxx"

#include <stdexcept>

#include <X11/extensions/XTest.h>

namespace wxclicker::mouse::x11 {

XTestMouseInputBackend::XTestMouseInputBackend()
{
    _display = ::XOpenDisplay(nullptr);

    if (!_display) {
        throw std::runtime_error("Failed to open display");
    }

    _root = DefaultRootWindow(_display);
}

XTestMouseInputBackend::~XTestMouseInputBackend()
{
    if (_display) {
        ::XCloseDisplay(_display);
    }
}

std::string_view XTestMouseInputBackend::GetName() const noexcept
{
    return "XTest";
}

void XTestMouseInputBackend::Down(MouseButton button) noexcept
{
    const auto xbutton{ToX11ButtonNumber(button)};

    if (xbutton < 0) {
        return;
    }

    ::XTestFakeButtonEvent(_display, xbutton, True, CurrentTime);
    ::XFlush(_display);
}

void XTestMouseInputBackend::Up(MouseButton button) noexcept
{
    const auto xbutton{ToX11ButtonNumber(button)};

    if (xbutton < 0) {
        return;
    }
    
    ::XTestFakeButtonEvent(_display, xbutton, False, CurrentTime);
    ::XFlush(_display);
}

void XTestMouseInputBackend::SetPosition(int x, int y) noexcept
{
    ::XTestFakeMotionEvent(_display, -1, x, y, CurrentTime);
    ::XFlush(_display);
}

int XTestMouseInputBackend::ToX11ButtonNumber(MouseButton button)
    const noexcept
{
    switch (button) {
        case MouseButton::Left:     return 1;
        case MouseButton::Middle:   return 2;
        case MouseButton::Right:    return 3;
        default: break;
    }

    return -1;
}

} // namespace wxclicker::mouse::x11

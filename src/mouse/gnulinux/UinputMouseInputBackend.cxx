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

#include "mouse/gnulinux/UinputMouseInputBackend.hxx"

#include <cstring>

#include <linux/uinput.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>

namespace wxclicker::mouse::gnulinux {

/* https://kernel.org/doc/html/v4.12/input/uinput.html */

UinputMouseInputBackend::UinputMouseInputBackend()
{
    constexpr auto UinputPath{"/dev/uinput"};
    constexpr auto DeviceName{"wxclicker-uinput"};

    _fd = ::open(UinputPath, O_WRONLY | O_NONBLOCK);

    if (_fd < 0) {
        throw std::runtime_error("Failed to open /dev/uinput");
    }

    ::ioctl(_fd, UI_SET_EVBIT, EV_KEY);
    ::ioctl(_fd, UI_SET_KEYBIT, BTN_LEFT);
    ::ioctl(_fd, UI_SET_KEYBIT, BTN_RIGHT);
    ::ioctl(_fd, UI_SET_KEYBIT, BTN_MIDDLE);

    ::ioctl(_fd, UI_SET_EVBIT, EV_REL);
    ::ioctl(_fd, UI_SET_RELBIT, REL_X);
    ::ioctl(_fd, UI_SET_RELBIT, REL_Y);

    uinput_setup usetup{};

    std::snprintf(usetup.name, UINPUT_MAX_NAME_SIZE, DeviceName);

    usetup.id.bustype = BUS_USB;
    usetup.id.vendor  = 0x1234; // Randomize?
    usetup.id.product = 0x5678;
    usetup.id.version = 1;

    if (::ioctl(_fd, UI_DEV_SETUP, &usetup) < 0) {
        throw std::runtime_error("Failed to setup device");
    }

    if (::ioctl(_fd, UI_DEV_CREATE) < 0) {
        throw std::runtime_error("Failed to create device");
    }
}

UinputMouseInputBackend::~UinputMouseInputBackend()
{
    if (_fd >= 0) {
        ::ioctl(_fd, UI_DEV_DESTROY);
        ::close(_fd);
    }
}

std::string_view UinputMouseInputBackend::GetName() const noexcept
{
    return "uinput";
}

void UinputMouseInputBackend::Down(MouseButton button) noexcept
{
    const auto keycode{ToUinputKeyCode(button)};

    if (keycode < 0) {
        return;
    }

    Emit(EV_KEY, keycode, 1);
    Emit(EV_SYN, SYN_REPORT, 0);
}

void UinputMouseInputBackend::Up(MouseButton button) noexcept
{
    const auto keycode{ToUinputKeyCode(button)};

    if (keycode < 0) {
        return;
    }

    Emit(EV_KEY, keycode, 0);
    Emit(EV_SYN, SYN_REPORT, 0);
}

void UinputMouseInputBackend::SetPosition(int x, int y) noexcept
{
    Emit(EV_REL, REL_X, INT32_MIN);
    Emit(EV_REL, REL_Y, INT32_MIN);
    Emit(EV_SYN, SYN_REPORT, 0);

    Emit(EV_REL, REL_X, x);
    Emit(EV_REL, REL_Y, y);
    Emit(EV_SYN, SYN_REPORT, 0);
}

void UinputMouseInputBackend::Emit(int type, int code, int val) noexcept
{
    input_event event{};

    ::gettimeofday(&event.time, nullptr);

    event.type = type;
    event.code = code;
    event.value = val;

    ::write(_fd, &event, sizeof(event));
}

int UinputMouseInputBackend::ToUinputKeyCode(MouseButton button)
    const noexcept
{
    switch (button) {
        case MouseButton::Left:     return BTN_LEFT;
        case MouseButton::Middle:   return BTN_MIDDLE;
        case MouseButton::Right:    return BTN_RIGHT;
        default: break;
    }

    return -1;
}

} // namespace wxclicker::mouse::gnulinux

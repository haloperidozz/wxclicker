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

#include "mouse/RegisterPlatformBackends.hxx"

#include <memory>

#include "mouse/MouseInputBackendRegistry.hxx"

#if defined(WXCLICKER_WIN32)
    #include "mouse/win32/SendInputBackend.hxx"
    #include "mouse/win32/NtUserSendInputBackend.hxx"
#endif

#if defined(WXCLICKER_LINUX)
    // TODO:
#endif

void wxclicker::mouse::RegisterPlatformBackends()
{
    auto& registry{MouseInputBackendRegistry::Instance()};

#if defined(WXCLICKER_WIN32)
    using namespace win32;

    registry.Register(std::make_shared<NtUserSendInputBackend>());
    registry.Register(std::make_shared<NtUserSendInputBackend>(true));
    registry.Register(std::make_shared<SendInputBackend>());
#endif

#if defined(WXCLICKER_LINUX)
    // TODO:
#endif
}

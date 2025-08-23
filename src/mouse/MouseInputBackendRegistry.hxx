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

#include <memory>
#include <string>
#include <string_view>
#include <vector>
#include <ranges>
#include <unordered_map>

#include "mouse/IMouseInputBackend.hxx"

namespace wxclicker::mouse {

class MouseInputBackendRegistry final
{
public:
    [[nodiscard]]
    static MouseInputBackendRegistry& Instance() noexcept;

    [[nodiscard]]
    MouseBackendPtr Get(std::string_view name) const noexcept;

    [[nodiscard]]
    std::vector<MouseBackendPtr> List() const noexcept;

    [[nodiscard]]
    bool IsAvailable(std::string_view name) const noexcept;

    [[nodiscard]]
    MouseBackendPtr GetDefaultBackend() const noexcept;

    bool Register(MouseBackendPtr backend) noexcept;

private:
    MouseInputBackendRegistry() = default;

    MouseInputBackendRegistry(const MouseInputBackendRegistry&) = delete;
    MouseInputBackendRegistry& operator=(const MouseInputBackendRegistry&) = delete;

    MouseInputBackendRegistry(MouseInputBackendRegistry&&) = delete;
    MouseInputBackendRegistry& operator=(MouseInputBackendRegistry&&) = delete;

    std::unordered_map<std::string, MouseBackendPtr> _backends;
};

} // namespace wxclicker::mouse

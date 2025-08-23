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

#include "mouse/MouseInputBackendRegistry.hxx"

namespace wxclicker::mouse {

MouseInputBackendRegistry& MouseInputBackendRegistry::Instance() noexcept
{
    static MouseInputBackendRegistry instance;
    return instance;
}

MouseBackendPtr MouseInputBackendRegistry::Get(std::string_view name) const noexcept
{
    const std::string key{name};

    if (const auto it = _backends.find(key); it != _backends.end()) {
        return it->second;
    }

    return nullptr;
}

std::vector<MouseBackendPtr> MouseInputBackendRegistry::List() const noexcept
{
    const auto values{_backends | std::views::values};
    
    return std::vector(values.begin(), values.end());
}

bool MouseInputBackendRegistry::IsAvailable(std::string_view name) const noexcept
{
    return _backends.contains(std::string{name});
}

MouseBackendPtr MouseInputBackendRegistry::GetDefaultBackend() const noexcept
{
    return _backends.empty() ? nullptr : _backends.begin()->second;
}

bool MouseInputBackendRegistry::Register(MouseBackendPtr backend) noexcept
{
    if (!backend) {
        return false;
    }

    auto [_, inserted]{
        _backends.emplace(backend->GetName(), std::move(backend))
    };

    return inserted;
}

} // namespace wxclicker::mouse

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

#include "application/ClickerApplication.hxx"

#include "mouse/RegisterPlatformBackends.hxx"

#include "ui/ClickerFrame.hxx"

namespace wxclicker::application {

bool ClickerApplication::OnInit()
{
    mouse::RegisterPlatformBackends();
    
    auto* pFrame{new ui::ClickerFrame{nullptr}};
    pFrame->Show(true);
    return true;
}

wxIMPLEMENT_APP(ClickerApplication);

} // namespace wxclicker::application

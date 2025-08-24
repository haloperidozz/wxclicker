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

#include "ui/generated/BaseClickerFrame.h"
#include "services/AutoClicker.hxx"
#include "mouse/IMouseInputBackend.hxx"

namespace wxclicker::ui {

class ClickerFrame final : public BaseClickerFrame
{
public:
    explicit ClickerFrame(wxWindow* parent);

protected:
    void OnIntervalChanged(wxSpinEvent& event) override;
    void OnMouseButtonChanged(wxCommandEvent& event) override;
    void OnClickTypeChanged(wxCommandEvent& event) override;
    void OnRepeatModeChanged(wxCommandEvent& event) override;
    void OnRepeatCountChanged(wxSpinEvent& event) override;
    void OnLocationModeChanged(wxCommandEvent& event) override;
    void OnPickLocation(wxCommandEvent& event) override;
    void OnLocationChanged(wxSpinEvent& event) override;
    void OnBackendChanged(wxCommandEvent& event) override;
    void OnHotkeyRecord(wxCommandEvent& event) override;
    void OnStart(wxCommandEvent& event) override;
    void OnStop(wxCommandEvent& event) override;

private:
    void InitBackends();

    services::AutoClicker          _clicker{};
    services::AutoClicker::Options _options{};
    mouse::MouseInputBackendShared _backend{nullptr};
};

} // namespace wxclicker::ui

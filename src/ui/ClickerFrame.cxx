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

#include "ui/ClickerFrame.hxx"

#include "mouse/MouseInputBackendRegistry.hxx"
#include "ui/PickScreenPointDialog.hxx"
#include "buildinfo/BuildInfo.hxx"

namespace wxclicker::ui {

ClickerFrame::ClickerFrame(wxWindow* pParent)
    : BaseClickerFrame(pParent, wxID_ANY,
        wxString::Format("%s %s", buildinfo::AppName, buildinfo::Version))
{
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

    InitBackends();

    _clicker.OnFinished([this]{
        CallAfter([this]{
            _pStart->Enable();
            _pStop->Disable();
        });
    });
}

void ClickerFrame::OnIntervalChanged([[maybe_unused]] wxSpinEvent& event)
{
    using namespace std::chrono;

    _options.interval  = hours(_pHours->GetValue());
    _options.interval += minutes(_pMinutes->GetValue());
    _options.interval += seconds(_pSeconds->GetValue());
    _options.interval += milliseconds(_pMilliseconds->GetValue());
}

void ClickerFrame::OnMouseButtonChanged([[maybe_unused]] wxCommandEvent& event)
{
    const auto selection{_pMouseButton->GetStringSelection()};

    if (selection == "Left") {
        _options.button = mouse::MouseButton::Left;
    }
    else if (selection == "Middle") {
        _options.button = mouse::MouseButton::Middle;
    }
    else if (selection == "Right") {
        _options.button = mouse::MouseButton::Right;
    }
}

void ClickerFrame::OnClickTypeChanged([[maybe_unused]] wxCommandEvent& event)
{
    const auto selection{_pClickType->GetStringSelection()};

    if (selection == "Single") {
        _options.clickCount = 1;
    }
    else if (selection == "Double") {
        _options.clickCount = 2;
    }
}

void ClickerFrame::OnRepeatModeChanged([[maybe_unused]] wxCommandEvent& event)
{
    if (_pRepeat->GetValue()) {
        _options.repeatTimes = _pRepeatCount->GetValue();
        _pRepeatCount->Enable();
    }
    else {
        _options.repeatTimes = std::nullopt;
        _pRepeatCount->Disable();
    }
}

void ClickerFrame::OnRepeatCountChanged([[maybe_unused]] wxSpinEvent& event)
{
    _options.repeatTimes = _pRepeatCount->GetValue();
}

void ClickerFrame::OnLocationModeChanged([[maybe_unused]] wxCommandEvent& event)
{
    const auto customLoc{_pCustomLocation->GetValue()};

    if (customLoc) {
        const auto x{_pLocX->GetValue()};
        const auto y{_pLocY->GetValue()};

        _options.clickPosition = std::make_pair(x, y);
    }
    else {
        _options.clickPosition = std::nullopt;
    }

    _pPickLocation->Enable(customLoc);
    _pLocX->Enable(customLoc);
    _pLocY->Enable(customLoc);
}

void ClickerFrame::OnPickLocation([[maybe_unused]] wxCommandEvent& event)
{
    if (const auto position = PickScreenPointDialog::Pick(this)) {
        const auto point{*position};

        _options.clickPosition = std::make_pair(point.x, point.y);

        _pLocX->SetValue(point.x);
        _pLocY->SetValue(point.y);
    }
}

void ClickerFrame::OnLocationChanged([[maybe_unused]] wxSpinEvent& event)
{
    const auto x{_pLocX->GetValue()};
    const auto y{_pLocY->GetValue()};

    _options.clickPosition = std::make_pair(x, y);
}

void ClickerFrame::OnBackendChanged([[maybe_unused]] wxCommandEvent& event)
{
    const auto selection{_pBackend->GetStringSelection()};

    const auto& registry{mouse::MouseInputBackendRegistry::Instance()};

    _backend = registry.Get(selection.ToStdString());
}

void ClickerFrame::OnHotkeyRecord([[maybe_unused]] wxCommandEvent& event)
{
    // TODO:
}

void ClickerFrame::OnStart([[maybe_unused]] wxCommandEvent& event)
{
    const auto& registry{mouse::MouseInputBackendRegistry::Instance()};

    if (!_backend) {
        _backend = registry.GetDefaultBackend();
    }

    _pStart->Disable();
    _pStop->Enable();

    _clicker.Configure(_options);
    _clicker.Start(_backend);
}

void ClickerFrame::OnStop([[maybe_unused]] wxCommandEvent& event)
{
    _clicker.RequestStop();
}

void ClickerFrame::InitBackends()
{
    const auto& registry{mouse::MouseInputBackendRegistry::Instance()};

    for (const auto& backend : registry.List()) {
        _pBackend->Append(wxString{backend->GetName()});
    }

    const auto defaultBackend{registry.GetDefaultBackend()};

    if (defaultBackend) {
        const auto name{defaultBackend->GetName()};
        const auto index{_pBackend->FindString(wxString{name})};

        if (index != wxNOT_FOUND) {
            _pBackend->SetSelection(index);
        }

        _backend = defaultBackend;
    }
}

} // namespace wxclicker::view

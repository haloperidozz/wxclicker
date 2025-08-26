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
        wxString::Format("%s [%s]", buildinfo::AppName, buildinfo::Version))
{
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

    InitBackends();

    _clicker.OnFinished([this]{
        CallAfter([this]{
            _startButton->Enable();
            _stopButton->Disable();
        });
    });
}

void ClickerFrame::OnIntervalChanged([[maybe_unused]] wxSpinEvent& event)
{
    using namespace std::chrono;

    _options.interval  = hours(_hoursSpinCtrl->GetValue());
    _options.interval += minutes(_minsSpinCtrl->GetValue());
    _options.interval += seconds(_secsSpinCtrl->GetValue());
    _options.interval += milliseconds(_millisSpinCtrl->GetValue());
}

void ClickerFrame::OnMouseButtonChanged([[maybe_unused]] wxCommandEvent& event)
{
    const auto mouseButton{_mouseButtonChoice->GetStringSelection()};

    if (mouseButton == "Left") {
        _options.button = mouse::MouseButton::Left;
    }
    else if (mouseButton == "Middle") {
        _options.button = mouse::MouseButton::Middle;
    }
    else if (mouseButton == "Right") {
        _options.button = mouse::MouseButton::Right;
    }
}

void ClickerFrame::OnClickTypeChanged([[maybe_unused]] wxCommandEvent& event)
{
    const auto clickType{_clickTypeChoice->GetStringSelection()};

    if (clickType == "Single") {
        _options.clickCount = 1;
    }
    else if (clickType == "Double") {
        _options.clickCount = 2;
    }
}

void ClickerFrame::OnRepeatModeChanged([[maybe_unused]] wxCommandEvent& event)
{
    const auto isRepeatUntilStopped{
        _repeatUntilStoppedRadioButton->GetValue()
    };

    if (isRepeatUntilStopped) {
        _options.repeatTimes = std::nullopt;
    }
    else {
        _options.repeatTimes = _repeatCountSpinCtrl->GetValue();
    }

    _repeatCountSpinCtrl->Enable(!isRepeatUntilStopped);
}

void ClickerFrame::OnRepeatCountChanged([[maybe_unused]] wxSpinEvent& event)
{
    _options.repeatTimes = _repeatCountSpinCtrl->GetValue();
}

void ClickerFrame::OnLocationModeChanged([[maybe_unused]] wxCommandEvent& event)
{
    const auto isCustomLocation{_customLocRadioButton->GetValue()};

    if (isCustomLocation) {
        const auto x{_xSpinCtrl->GetValue()};
        const auto y{_ySpinCtrl->GetValue()};

        _options.clickPosition = std::make_pair(x, y);
    }
    else {
        _options.clickPosition = std::nullopt;
    }

    _pickLocationButton->Enable(isCustomLocation);
    _xSpinCtrl->Enable(isCustomLocation);
    _ySpinCtrl->Enable(isCustomLocation);
}

void ClickerFrame::OnPickLocation([[maybe_unused]] wxCommandEvent& event)
{
    if (const auto point = PickScreenPointDialog::Pick(this)) {
        _options.clickPosition = std::make_pair((*point).x, (*point).y);

        _xSpinCtrl->SetValue((*point).x);
        _ySpinCtrl->SetValue((*point).y);
    }
}

void ClickerFrame::OnLocationChanged([[maybe_unused]] wxSpinEvent& event)
{
    const auto x{_xSpinCtrl->GetValue()};
    const auto y{_ySpinCtrl->GetValue()};

    _options.clickPosition = std::make_pair(x, y);
}

void ClickerFrame::OnBackendChanged([[maybe_unused]] wxCommandEvent& event)
{
    const auto selectedBackend{_backendChoice->GetStringSelection()};

    const auto& registry{mouse::MouseInputBackendRegistry::Instance()};

    _backend = registry.Get(selectedBackend.ToStdString());
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

    _startButton->Disable();
    _stopButton->Enable();

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
        const auto backendName{wxString{backend->GetName()}};

        _backendChoice->Append(backendName);
    }

    const auto defaultBackend{registry.GetDefaultBackend()};

    if (defaultBackend) {
        const auto backendName{wxString{defaultBackend->GetName()}};

        const auto index{_backendChoice->FindString(backendName)};

        if (index != wxNOT_FOUND) {
            _backendChoice->SetSelection(index);
        }

        _backend = defaultBackend;
    }
}

} // namespace wxclicker::view

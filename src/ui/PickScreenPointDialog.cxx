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

#include "ui/PickScreenPointDialog.hxx"

#include <wx/dcbuffer.h>

namespace wxclicker::ui {

PickScreenPointDialog::PickScreenPointDialog(wxWindow* pParent)
    : wxDialog(pParent, wxID_ANY, "",
               wxDefaultPosition, wxGetDisplaySize(), wxSTAY_ON_TOP)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    SetTransparent(128);

    Bind(wxEVT_LEFT_DOWN, &PickScreenPointDialog::OnMouseClick, this);
    Bind(wxEVT_MOTION, &PickScreenPointDialog::OnMouseMove, this);
    Bind(wxEVT_PAINT, &PickScreenPointDialog::OnPaint, this);

    ShowFullScreen(true);
}

std::optional<wxPoint> PickScreenPointDialog::Pick(wxWindow* pParent)
{
    PickScreenPointDialog dialog{pParent};

    if (dialog.ShowModal() == wxID_OK) {
        return dialog._pickedPoint;
    }

    return std::nullopt;
}

void PickScreenPointDialog::OnMouseClick(wxMouseEvent& event)
{
    _pickedPoint = ClientToScreen(event.GetPosition());
    EndDialog(wxID_OK);
}

void PickScreenPointDialog::OnMouseMove(wxMouseEvent& event)
{
    const auto pos{event.GetPosition()};
    SetToolTip(wxString::Format("X: %d Y: %d", pos.x, pos.y));
}

void PickScreenPointDialog::OnPaint([[maybe_unused]] wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc{this};

    dc.SetBrush(*wxBLACK_BRUSH);
    dc.SetPen(*wxBLACK_PEN);
    dc.DrawRectangle(GetClientRect());
}

} // namespace wxclicker::ui

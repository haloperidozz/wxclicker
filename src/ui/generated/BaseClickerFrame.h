///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/choice.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/textctrl.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class BaseClickerFrame
///////////////////////////////////////////////////////////////////////////////
class BaseClickerFrame : public wxFrame
{
	private:

	protected:
		wxSpinCtrl* _hoursSpinCtrl;
		wxSpinCtrl* _minsSpinCtrl;
		wxSpinCtrl* _secsSpinCtrl;
		wxSpinCtrl* _millisSpinCtrl;
		wxChoice* _mouseButtonChoice;
		wxChoice* _clickTypeChoice;
		wxRadioButton* _repeatRadioButton;
		wxSpinCtrl* _repeatCountSpinCtrl;
		wxRadioButton* _repeatUntilStoppedRadioButton;
		wxRadioButton* _currentLocRadioButton;
		wxRadioButton* _customLocRadioButton;
		wxButton* _pickLocationButton;
		wxSpinCtrl* _xSpinCtrl;
		wxSpinCtrl* _ySpinCtrl;
		wxChoice* _backendChoice;
		wxButton* _hotkeyButton;
		wxTextCtrl* _hotkeyText;
		wxButton* _startButton;
		wxButton* _stopButton;

		// Virtual event handlers, override them in your derived class
		virtual void OnIntervalChanged( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnMouseButtonChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickTypeChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRepeatModeChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRepeatCountChanged( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnLocationModeChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPickLocation( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLocationChanged( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnBackendChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHotkeyRecord( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStart( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStop( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseClickerFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 510,420 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BaseClickerFrame();

};


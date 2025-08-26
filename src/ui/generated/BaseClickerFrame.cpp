///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BaseClickerFrame.h"

///////////////////////////////////////////////////////////////////////////

BaseClickerFrame::BaseClickerFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 510,420 ), wxDefaultSize );

	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* clickIntervalSizer;
	clickIntervalSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Click Interval") ), wxHORIZONTAL );

	wxStaticText* hoursText;
	hoursText = new wxStaticText( clickIntervalSizer->GetStaticBox(), wxID_ANY, _("Hours:"), wxDefaultPosition, wxDefaultSize, 0 );
	hoursText->Wrap( -1 );
	clickIntervalSizer->Add( hoursText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_hoursSpinCtrl = new wxSpinCtrl( clickIntervalSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9999999, 0 );
	clickIntervalSizer->Add( _hoursSpinCtrl, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* minsText;
	minsText = new wxStaticText( clickIntervalSizer->GetStaticBox(), wxID_ANY, _("Mins:"), wxDefaultPosition, wxDefaultSize, 0 );
	minsText->Wrap( -1 );
	clickIntervalSizer->Add( minsText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_minsSpinCtrl = new wxSpinCtrl( clickIntervalSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9999999, 0 );
	clickIntervalSizer->Add( _minsSpinCtrl, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* secsText;
	secsText = new wxStaticText( clickIntervalSizer->GetStaticBox(), wxID_ANY, _("Secs:"), wxDefaultPosition, wxDefaultSize, 0 );
	secsText->Wrap( -1 );
	clickIntervalSizer->Add( secsText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_secsSpinCtrl = new wxSpinCtrl( clickIntervalSizer->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9999999, 0 );
	clickIntervalSizer->Add( _secsSpinCtrl, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* millisText;
	millisText = new wxStaticText( clickIntervalSizer->GetStaticBox(), wxID_ANY, _("Millis:"), wxDefaultPosition, wxDefaultSize, 0 );
	millisText->Wrap( -1 );
	clickIntervalSizer->Add( millisText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_millisSpinCtrl = new wxSpinCtrl( clickIntervalSizer->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 10, 9999999, 0 );
	clickIntervalSizer->Add( _millisSpinCtrl, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	mainSizer->Add( clickIntervalSizer, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* mainOptionsSizer;
	mainOptionsSizer = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* clickOptionsSizer;
	clickOptionsSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Click Options") ), wxVERTICAL );

	wxBoxSizer* mouseButtonSizer;
	mouseButtonSizer = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* mouseButtonText;
	mouseButtonText = new wxStaticText( clickOptionsSizer->GetStaticBox(), wxID_ANY, _("Mouse Button:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	mouseButtonText->Wrap( -1 );
	mouseButtonSizer->Add( mouseButtonText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxString _mouseButtonChoiceChoices[] = { _("Left"), _("Middle"), _("Right") };
	int _mouseButtonChoiceNChoices = sizeof( _mouseButtonChoiceChoices ) / sizeof( wxString );
	_mouseButtonChoice = new wxChoice( clickOptionsSizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, _mouseButtonChoiceNChoices, _mouseButtonChoiceChoices, 0 );
	_mouseButtonChoice->SetSelection( 0 );
	mouseButtonSizer->Add( _mouseButtonChoice, 2, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	clickOptionsSizer->Add( mouseButtonSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* clickTypeSizer;
	clickTypeSizer = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* clickTypeText;
	clickTypeText = new wxStaticText( clickOptionsSizer->GetStaticBox(), wxID_ANY, _("Click Type:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	clickTypeText->Wrap( -1 );
	clickTypeSizer->Add( clickTypeText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxString _clickTypeChoiceChoices[] = { _("Single"), _("Double") };
	int _clickTypeChoiceNChoices = sizeof( _clickTypeChoiceChoices ) / sizeof( wxString );
	_clickTypeChoice = new wxChoice( clickOptionsSizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, _clickTypeChoiceNChoices, _clickTypeChoiceChoices, 0 );
	_clickTypeChoice->SetSelection( 0 );
	clickTypeSizer->Add( _clickTypeChoice, 2, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	clickOptionsSizer->Add( clickTypeSizer, 1, wxEXPAND, 5 );


	mainOptionsSizer->Add( clickOptionsSizer, 1, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* clickRepeatSizer;
	clickRepeatSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Click Repeat") ), wxVERTICAL );

	wxBoxSizer* repeatLineSizer;
	repeatLineSizer = new wxBoxSizer( wxHORIZONTAL );

	_repeatRadioButton = new wxRadioButton( clickRepeatSizer->GetStaticBox(), wxID_ANY, _("Repeat"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	repeatLineSizer->Add( _repeatRadioButton, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxTOP, 5 );

	_repeatCountSpinCtrl = new wxSpinCtrl( clickRepeatSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL|wxSP_ARROW_KEYS, 1, 999999, 1 );
	_repeatCountSpinCtrl->Enable( false );

	repeatLineSizer->Add( _repeatCountSpinCtrl, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );

	wxStaticText* timesText;
	timesText = new wxStaticText( clickRepeatSizer->GetStaticBox(), wxID_ANY, _("times"), wxDefaultPosition, wxDefaultSize, 0 );
	timesText->Wrap( -1 );
	repeatLineSizer->Add( timesText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxTOP, 5 );


	clickRepeatSizer->Add( repeatLineSizer, 1, wxEXPAND, 5 );

	_repeatUntilStoppedRadioButton = new wxRadioButton( clickRepeatSizer->GetStaticBox(), wxID_ANY, _("Repeat until stopped"), wxDefaultPosition, wxDefaultSize, 0 );
	_repeatUntilStoppedRadioButton->SetValue( true );
	clickRepeatSizer->Add( _repeatUntilStoppedRadioButton, 1, wxALL, 5 );


	mainOptionsSizer->Add( clickRepeatSizer, 1, wxALL|wxEXPAND, 5 );


	mainSizer->Add( mainOptionsSizer, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* cursorPositionSizer;
	cursorPositionSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Cursor Position") ), wxHORIZONTAL );

	_currentLocRadioButton = new wxRadioButton( cursorPositionSizer->GetStaticBox(), wxID_ANY, _("Current location"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	_currentLocRadioButton->SetValue( true );
	cursorPositionSizer->Add( _currentLocRadioButton, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* locationLineSizer;
	locationLineSizer = new wxBoxSizer( wxHORIZONTAL );

	_customLocRadioButton = new wxRadioButton( cursorPositionSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	locationLineSizer->Add( _customLocRadioButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pickLocationButton = new wxButton( cursorPositionSizer->GetStaticBox(), wxID_ANY, _("Pick Location"), wxDefaultPosition, wxDefaultSize, 0 );
	_pickLocationButton->Enable( false );

	locationLineSizer->Add( _pickLocationButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* xText;
	xText = new wxStaticText( cursorPositionSizer->GetStaticBox(), wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	xText->Wrap( -1 );
	locationLineSizer->Add( xText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_xSpinCtrl = new wxSpinCtrl( cursorPositionSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 65535, 0 );
	_xSpinCtrl->Enable( false );

	locationLineSizer->Add( _xSpinCtrl, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* yText;
	yText = new wxStaticText( cursorPositionSizer->GetStaticBox(), wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	yText->Wrap( -1 );
	locationLineSizer->Add( yText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_ySpinCtrl = new wxSpinCtrl( cursorPositionSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 65535, 0 );
	_ySpinCtrl->Enable( false );

	locationLineSizer->Add( _ySpinCtrl, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	cursorPositionSizer->Add( locationLineSizer, 1, wxEXPAND, 5 );


	mainSizer->Add( cursorPositionSizer, 1, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* additionalOptionsSizer;
	additionalOptionsSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Additional Options") ), wxVERTICAL );

	wxBoxSizer* backendOptions;
	backendOptions = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* backendText;
	backendText = new wxStaticText( additionalOptionsSizer->GetStaticBox(), wxID_ANY, _("Backend:"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	backendText->Wrap( -1 );
	backendOptions->Add( backendText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxArrayString _backendChoiceChoices;
	_backendChoice = new wxChoice( additionalOptionsSizer->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, _backendChoiceChoices, 0 );
	_backendChoice->SetSelection( 0 );
	backendOptions->Add( _backendChoice, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	additionalOptionsSizer->Add( backendOptions, 1, wxEXPAND, 5 );

	wxBoxSizer* hotkeyOptionsSizer;
	hotkeyOptionsSizer = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* hotkeyText;
	hotkeyText = new wxStaticText( additionalOptionsSizer->GetStaticBox(), wxID_ANY, _("Hotkey:"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	hotkeyText->Wrap( -1 );
	hotkeyOptionsSizer->Add( hotkeyText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_hotkeyButton = new wxButton( additionalOptionsSizer->GetStaticBox(), wxID_ANY, _("Start / Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	hotkeyOptionsSizer->Add( _hotkeyButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_hotkeyText = new wxTextCtrl( additionalOptionsSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	_hotkeyText->Enable( false );

	hotkeyOptionsSizer->Add( _hotkeyText, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	additionalOptionsSizer->Add( hotkeyOptionsSizer, 1, wxEXPAND, 5 );


	mainSizer->Add( additionalOptionsSizer, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* buttonsSizer;
	buttonsSizer = new wxBoxSizer( wxHORIZONTAL );

	_startButton = new wxButton( this, wxID_ANY, _("Start"), wxDefaultPosition, wxSize( -1,35 ), 0 );

	_startButton->SetDefault();
	buttonsSizer->Add( _startButton, 1, wxALL, 5 );

	_stopButton = new wxButton( this, wxID_ANY, _("Stop"), wxDefaultPosition, wxSize( -1,35 ), 0 );
	_stopButton->Enable( false );

	buttonsSizer->Add( _stopButton, 1, wxALL, 5 );


	mainSizer->Add( buttonsSizer, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( mainSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	_hoursSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnIntervalChanged ), NULL, this );
	_minsSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnIntervalChanged ), NULL, this );
	_secsSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnIntervalChanged ), NULL, this );
	_millisSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnIntervalChanged ), NULL, this );
	_mouseButtonChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnMouseButtonChanged ), NULL, this );
	_clickTypeChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnClickTypeChanged ), NULL, this );
	_repeatRadioButton->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnRepeatModeChanged ), NULL, this );
	_repeatCountSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnRepeatCountChanged ), NULL, this );
	_repeatUntilStoppedRadioButton->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnRepeatModeChanged ), NULL, this );
	_currentLocRadioButton->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnLocationModeChanged ), NULL, this );
	_customLocRadioButton->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnLocationModeChanged ), NULL, this );
	_pickLocationButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClickerFrame::OnPickLocation ), NULL, this );
	_xSpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnLocationChanged ), NULL, this );
	_ySpinCtrl->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnLocationChanged ), NULL, this );
	_backendChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnBackendChanged ), NULL, this );
	_hotkeyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClickerFrame::OnHotkeyRecord ), NULL, this );
	_startButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClickerFrame::OnStart ), NULL, this );
	_stopButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClickerFrame::OnStop ), NULL, this );
}

BaseClickerFrame::~BaseClickerFrame()
{
}

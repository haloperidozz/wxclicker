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

	wxBoxSizer* MainBoxSizer;
	MainBoxSizer = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* ClickInterval;
	ClickInterval = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Click Interval") ), wxHORIZONTAL );

	wxStaticText* HoursText;
	HoursText = new wxStaticText( ClickInterval->GetStaticBox(), wxID_ANY, _("Hours:"), wxDefaultPosition, wxDefaultSize, 0 );
	HoursText->Wrap( -1 );
	ClickInterval->Add( HoursText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pHours = new wxSpinCtrl( ClickInterval->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9999999, 0 );
	ClickInterval->Add( _pHours, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* MinutesText;
	MinutesText = new wxStaticText( ClickInterval->GetStaticBox(), wxID_ANY, _("Mins:"), wxDefaultPosition, wxDefaultSize, 0 );
	MinutesText->Wrap( -1 );
	ClickInterval->Add( MinutesText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pMinutes = new wxSpinCtrl( ClickInterval->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9999999, 0 );
	ClickInterval->Add( _pMinutes, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* SecondsText;
	SecondsText = new wxStaticText( ClickInterval->GetStaticBox(), wxID_ANY, _("Secs:"), wxDefaultPosition, wxDefaultSize, 0 );
	SecondsText->Wrap( -1 );
	ClickInterval->Add( SecondsText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pSeconds = new wxSpinCtrl( ClickInterval->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9999999, 0 );
	ClickInterval->Add( _pSeconds, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* MillisecondsText;
	MillisecondsText = new wxStaticText( ClickInterval->GetStaticBox(), wxID_ANY, _("Millis:"), wxDefaultPosition, wxDefaultSize, 0 );
	MillisecondsText->Wrap( -1 );
	ClickInterval->Add( MillisecondsText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pMilliseconds = new wxSpinCtrl( ClickInterval->GetStaticBox(), wxID_ANY, wxT("100"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 10, 9999999, 0 );
	ClickInterval->Add( _pMilliseconds, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	MainBoxSizer->Add( ClickInterval, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* MainOptions;
	MainOptions = new wxBoxSizer( wxHORIZONTAL );

	wxStaticBoxSizer* ClickOptions;
	ClickOptions = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Click Options") ), wxVERTICAL );

	wxBoxSizer* MouseButtonSizer;
	MouseButtonSizer = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* MouseButtonText;
	MouseButtonText = new wxStaticText( ClickOptions->GetStaticBox(), wxID_ANY, _("Mouse Button:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	MouseButtonText->Wrap( -1 );
	MouseButtonSizer->Add( MouseButtonText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxString _pMouseButtonChoices[] = { _("Left"), _("Middle"), _("Right") };
	int _pMouseButtonNChoices = sizeof( _pMouseButtonChoices ) / sizeof( wxString );
	_pMouseButton = new wxChoice( ClickOptions->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, _pMouseButtonNChoices, _pMouseButtonChoices, 0 );
	_pMouseButton->SetSelection( 0 );
	MouseButtonSizer->Add( _pMouseButton, 2, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	ClickOptions->Add( MouseButtonSizer, 1, wxEXPAND, 5 );

	wxBoxSizer* ClickTypeSizer;
	ClickTypeSizer = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* ClickTypeText;
	ClickTypeText = new wxStaticText( ClickOptions->GetStaticBox(), wxID_ANY, _("Click Type:"), wxDefaultPosition, wxSize( 80,-1 ), 0 );
	ClickTypeText->Wrap( -1 );
	ClickTypeSizer->Add( ClickTypeText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxString _pClickTypeChoices[] = { _("Single"), _("Double") };
	int _pClickTypeNChoices = sizeof( _pClickTypeChoices ) / sizeof( wxString );
	_pClickType = new wxChoice( ClickOptions->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, _pClickTypeNChoices, _pClickTypeChoices, 0 );
	_pClickType->SetSelection( 0 );
	ClickTypeSizer->Add( _pClickType, 2, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	ClickOptions->Add( ClickTypeSizer, 1, wxEXPAND, 5 );


	MainOptions->Add( ClickOptions, 1, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* ClickRepeat;
	ClickRepeat = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Click Repeat") ), wxVERTICAL );

	wxBoxSizer* RepeatLine;
	RepeatLine = new wxBoxSizer( wxHORIZONTAL );

	_pRepeat = new wxRadioButton( ClickRepeat->GetStaticBox(), wxID_ANY, _("Repeat"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	RepeatLine->Add( _pRepeat, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxLEFT|wxTOP, 5 );

	_pRepeatCount = new wxSpinCtrl( ClickRepeat->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL|wxSP_ARROW_KEYS, 1, 999999, 1 );
	_pRepeatCount->Enable( false );

	RepeatLine->Add( _pRepeatCount, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5 );

	wxStaticText* TimesText;
	TimesText = new wxStaticText( ClickRepeat->GetStaticBox(), wxID_ANY, _("times"), wxDefaultPosition, wxDefaultSize, 0 );
	TimesText->Wrap( -1 );
	RepeatLine->Add( TimesText, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxTOP, 5 );


	ClickRepeat->Add( RepeatLine, 1, wxEXPAND, 5 );

	_pRepeatUntilStopped = new wxRadioButton( ClickRepeat->GetStaticBox(), wxID_ANY, _("Repeat until stopped"), wxDefaultPosition, wxDefaultSize, 0 );
	_pRepeatUntilStopped->SetValue( true );
	ClickRepeat->Add( _pRepeatUntilStopped, 1, wxALL, 5 );


	MainOptions->Add( ClickRepeat, 1, wxALL|wxEXPAND, 5 );


	MainBoxSizer->Add( MainOptions, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* CursorPosition;
	CursorPosition = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Cursor Position") ), wxHORIZONTAL );

	_pCurrentLocation = new wxRadioButton( CursorPosition->GetStaticBox(), wxID_ANY, _("Current location"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	_pCurrentLocation->SetValue( true );
	CursorPosition->Add( _pCurrentLocation, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxBoxSizer* LocationLine;
	LocationLine = new wxBoxSizer( wxHORIZONTAL );

	_pCustomLocation = new wxRadioButton( CursorPosition->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	LocationLine->Add( _pCustomLocation, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pPickLocation = new wxButton( CursorPosition->GetStaticBox(), wxID_ANY, _("Pick Location"), wxDefaultPosition, wxDefaultSize, 0 );
	_pPickLocation->Enable( false );

	LocationLine->Add( _pPickLocation, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* X;
	X = new wxStaticText( CursorPosition->GetStaticBox(), wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	X->Wrap( -1 );
	LocationLine->Add( X, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pLocX = new wxSpinCtrl( CursorPosition->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 65535, 0 );
	_pLocX->Enable( false );

	LocationLine->Add( _pLocX, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxStaticText* Y;
	Y = new wxStaticText( CursorPosition->GetStaticBox(), wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	Y->Wrap( -1 );
	LocationLine->Add( Y, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pLocY = new wxSpinCtrl( CursorPosition->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 65535, 0 );
	_pLocY->Enable( false );

	LocationLine->Add( _pLocY, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	CursorPosition->Add( LocationLine, 1, wxEXPAND, 5 );


	MainBoxSizer->Add( CursorPosition, 1, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* AdditionalOptions;
	AdditionalOptions = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Additional Options") ), wxVERTICAL );

	wxBoxSizer* BackendOptions;
	BackendOptions = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* BackendText;
	BackendText = new wxStaticText( AdditionalOptions->GetStaticBox(), wxID_ANY, _("Backend:"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	BackendText->Wrap( -1 );
	BackendOptions->Add( BackendText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxArrayString _pBackendChoices;
	_pBackend = new wxChoice( AdditionalOptions->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, _pBackendChoices, 0 );
	_pBackend->SetSelection( 0 );
	BackendOptions->Add( _pBackend, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	AdditionalOptions->Add( BackendOptions, 1, wxEXPAND, 5 );

	wxBoxSizer* HotkeyOptions;
	HotkeyOptions = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* HotkeyText;
	HotkeyText = new wxStaticText( AdditionalOptions->GetStaticBox(), wxID_ANY, _("Hotkey:"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	HotkeyText->Wrap( -1 );
	HotkeyOptions->Add( HotkeyText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pHotkeyButton = new wxButton( AdditionalOptions->GetStaticBox(), wxID_ANY, _("Start / Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	HotkeyOptions->Add( _pHotkeyButton, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	_pHotkeyText = new wxTextCtrl( AdditionalOptions->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	_pHotkeyText->Enable( false );

	HotkeyOptions->Add( _pHotkeyText, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	AdditionalOptions->Add( HotkeyOptions, 1, wxEXPAND, 5 );


	MainBoxSizer->Add( AdditionalOptions, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* Buttons;
	Buttons = new wxBoxSizer( wxHORIZONTAL );

	_pStart = new wxButton( this, wxID_ANY, _("Start"), wxDefaultPosition, wxSize( -1,35 ), 0 );

	_pStart->SetDefault();
	Buttons->Add( _pStart, 1, wxALL, 5 );

	_pStop = new wxButton( this, wxID_ANY, _("Stop"), wxDefaultPosition, wxSize( -1,35 ), 0 );
	_pStop->Enable( false );

	Buttons->Add( _pStop, 1, wxALL, 5 );


	MainBoxSizer->Add( Buttons, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( MainBoxSizer );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	_pHours->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnIntervalChanged ), NULL, this );
	_pMinutes->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnIntervalChanged ), NULL, this );
	_pSeconds->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnIntervalChanged ), NULL, this );
	_pMilliseconds->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnIntervalChanged ), NULL, this );
	_pMouseButton->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnMouseButtonChanged ), NULL, this );
	_pClickType->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnClickTypeChanged ), NULL, this );
	_pRepeat->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnRepeatModeChanged ), NULL, this );
	_pRepeatCount->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnRepeatCountChanged ), NULL, this );
	_pRepeatUntilStopped->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnRepeatModeChanged ), NULL, this );
	_pCurrentLocation->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnLocationModeChanged ), NULL, this );
	_pCustomLocation->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnLocationModeChanged ), NULL, this );
	_pPickLocation->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClickerFrame::OnPickLocation ), NULL, this );
	_pLocX->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnLocationChanged ), NULL, this );
	_pLocY->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( BaseClickerFrame::OnLocationChanged ), NULL, this );
	_pBackend->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseClickerFrame::OnBackendChanged ), NULL, this );
	_pHotkeyButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClickerFrame::OnHotkeyRecord ), NULL, this );
	_pStart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClickerFrame::OnStart ), NULL, this );
	_pStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseClickerFrame::OnStop ), NULL, this );
}

BaseClickerFrame::~BaseClickerFrame()
{
}

/***************************************************************
 * Name:      FormationMediaPlayerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2019-10-08
 * Copyright:  ()
 * License:
 **************************************************************/

#include "FormationMediaPlayerMain.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/mediactrl.h>

//(*InternalHeaders(FormationMediaPlayerFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(FormationMediaPlayerFrame)
const long FormationMediaPlayerFrame::ID_BUTTON1 = wxNewId();
const long FormationMediaPlayerFrame::ID_BUTTON2 = wxNewId();
const long FormationMediaPlayerFrame::ID_SLIDER1 = wxNewId();
const long FormationMediaPlayerFrame::ID_TEXTCTRL1 = wxNewId();
const long FormationMediaPlayerFrame::idMenuImport = wxNewId();
const long FormationMediaPlayerFrame::idMenuQuit = wxNewId();
const long FormationMediaPlayerFrame::idMenuAbout = wxNewId();
const long FormationMediaPlayerFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(FormationMediaPlayerFrame,wxFrame)
    //(*EventTable(FormationMediaPlayerFrame)
    //*)
END_EVENT_TABLE()

wxMediaCtrl* mediactrl1;
bool loaded = false;

FormationMediaPlayerFrame::FormationMediaPlayerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(FormationMediaPlayerFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(1, 4, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Play"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    mediactrl1  =  new wxMediaCtrl();

    mediactrl1->Create(this, wxID_ANY, wxEmptyString , wxDefaultPosition, wxDefaultSize, 0);
    FlexGridSizer1->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Pause"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer1->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider1 = new wxSlider(this, ID_SLIDER1, 0, 0, 100, wxDefaultPosition, wxSize(310,27), 0, wxDefaultValidator, _T("ID_SLIDER1"));
    FlexGridSizer1->Add(Slider1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idMenuImport, _("Import Music"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FormationMediaPlayerFrame::OnPlayButtonClick);
    Connect(idMenuImport,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&FormationMediaPlayerFrame::OnImportMusic);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&FormationMediaPlayerFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&FormationMediaPlayerFrame::OnAbout);
    //*)
}

FormationMediaPlayerFrame::~FormationMediaPlayerFrame()
{
    //(*Destroy(FormationMediaPlayerFrame)
    //*)
}

void FormationMediaPlayerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void FormationMediaPlayerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void FormationMediaPlayerFrame::OnImportMusic(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, _("Open File"), _(""), _(""), _("music files (*.mp3)|*.mp3"), wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if(openFileDialog.ShowModal() == wxID_CANCEL) return;

    *TextCtrl1 << openFileDialog.GetPath();

    loaded = mediactrl1->Load(openFileDialog.GetPath());
}

void FormationMediaPlayerFrame::OnPlayButtonClick(wxCommandEvent& event)
{
    if(loaded) mediactrl1->Play();
}

/***************************************************************
 * Name:      Tic_Tac_ToeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2019-07-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Tic_Tac_ToeMain.h"
#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include "Board_Piece.h"
#include "Board.h"
//(*InternalHeaders(Tic_Tac_ToeFrame)
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

//(*IdInit(Tic_Tac_ToeFrame)
const long Tic_Tac_ToeFrame::ID_PANEL1 = wxNewId();
const long Tic_Tac_ToeFrame::ID_TEXTCTRL1 = wxNewId();
const long Tic_Tac_ToeFrame::ID_STATICTEXT1 = wxNewId();
const long Tic_Tac_ToeFrame::ID_BUTTON1 = wxNewId();
const long Tic_Tac_ToeFrame::idMenuQuit = wxNewId();
const long Tic_Tac_ToeFrame::idMenuAbout = wxNewId();
const long Tic_Tac_ToeFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Tic_Tac_ToeFrame,wxFrame)
    //(*EventTable(Tic_Tac_ToeFrame)
    //*)
END_EVENT_TABLE()

namespace TicTacToe{
    Board* TicTacToe;
    int winner;
}

void DrawBoard(wxDC& dc);

Tic_Tac_ToeFrame::Tic_Tac_ToeFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Tic_Tac_ToeFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxFlexGridSizer* FlexGridSizer3;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetMinSize(wxSize(300,300));
    Panel1->SetBackgroundColour(wxColour(255,255,255));
    wxPaintDC dc(Panel1);
    DrawBoard(dc);
    FlexGridSizer2->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(3, 1, 0, 0);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(160,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer3->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Current Score:\nPlayer One:\nPlayer Two: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("New Game"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
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

    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Tic_Tac_ToeFrame::OnPaint,0,this);
    Panel1->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Tic_Tac_ToeFrame::OnPanel1LeftDClick,0,this);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Tic_Tac_ToeFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Tic_Tac_ToeFrame::OnAbout);
    //*)
}

Board* InitBoard(){

    Board* board = new Board();

    return board;

}

void DrawBoard(wxDC& dc){
    dc.SetPen(wxPen(wxColour(0,0,0),3));
    dc.SetBrush(*wxBLACK_BRUSH);

    dc.DrawLine(0,100,300,100);
    dc.DrawLine(0,200,300,200);
    dc.DrawLine(100, 0, 100,300);
    dc.DrawLine(200, 0, 200,300);

}
/*
void DrawXO(wxClientDC& dc){
    dc.SetPen(wxPen(wxColour(0,0,0),3));
    dc.SetBrush(*wxBLACK_BRUSH);

    dc.DrawCircle(150,150, 46);


    dc.SetPen(wxPen(wxColour(255,255,255),3));
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.DrawCircle(150,150, 43);
    //Refresh();
}*/

Tic_Tac_ToeFrame::~Tic_Tac_ToeFrame()
{
    //(*Destroy(Tic_Tac_ToeFrame)
    //*)
}

void Tic_Tac_ToeFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Tic_Tac_ToeFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Tic_Tac_ToeFrame::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(Panel1);
    DrawBoard(dc);

    TicTacToe::TicTacToe = InitBoard();
    event.Skip();
}

void Tic_Tac_ToeFrame::OnPanel1LeftDClick(wxMouseEvent& event)
{
    if(!TicTacToe::TicTacToe->GameOver){

        wxClientDC dc(Panel1);
        dc.SetPen(wxPen(wxColour(0,0,0),3));
        dc.SetBrush(*wxBLACK_BRUSH);

        TicTacToe::TicTacToe->Click(event.GetPosition(), dc);
        if(TicTacToe::TicTacToe->numTaken >= 5){
            TicTacToe::winner =  TicTacToe::TicTacToe->CheckWin();
        }
        if(TicTacToe::winner == 1){
            TextCtrl1->SetValue(_("Player 1 Wins"));
        }else if(TicTacToe::winner == 2){
            TextCtrl1->SetValue(_("Player 2 Wins"));
        }
    }
}

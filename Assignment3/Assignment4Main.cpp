/***************************************************************
 * Name:      Assignment4Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2019-02-18
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Assignment4Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Assignment4Frame)
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

//(*IdInit(Assignment4Frame)
const long Assignment4Frame::ID_PANEL1 = wxNewId();
const long Assignment4Frame::idMenuQuit = wxNewId();
const long Assignment4Frame::idMenuAbout = wxNewId();
const long Assignment4Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Assignment4Frame,wxFrame)
    //(*EventTable(Assignment4Frame)
    //*)
END_EVENT_TABLE()

wxPoint MyAry[100];
int count = 0;
bool DrawMode = false;


Assignment4Frame::Assignment4Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Assignment4Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxGridSizer* GridSizer1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(462,161));
    wxPoint MyAry[100];
    int count = 0;
    GridSizer1 = new wxGridSizer(1, 1, 0, 0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(355,263), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(255,255,255));
    GridSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridSizer1);
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
    SetSizer(GridSizer1);
    Layout();

    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Assignment4Frame::OnPanel1Paint,0,this);
    Panel1->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Assignment4Frame::OnPanel1LeftDClick,0,this);
    Panel1->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&Assignment4Frame::OnPanel1LeftDoubleClick,0,this);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Assignment4Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Assignment4Frame::OnAbout);
    //*)

}

Assignment4Frame::~Assignment4Frame()
{
    //(*Destroy(Assignment4Frame)
    //*)
}

void Assignment4Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Assignment4Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void Assignment4Frame::OnPanel1LeftDClick(wxMouseEvent& event)
{
    if(count < 99 && (MyAry[count] != event.GetPosition())){
        MyAry[count] = event.GetPosition();
        count++;
    }
    else if(count >= 100 || DrawMode == true){
        event.Skip();
    }
}

void Draw(wxDC& dc)
{
    dc.SetPen(wxPen(wxColour(0,0,0), 3));
    dc.SetBrush(*wxBLACK_BRUSH);

    for(int x = 0; x < count-1; x++){
        dc.DrawLine(MyAry[x].x, MyAry[x].y, MyAry[x+1].x, MyAry[x+1].y);
    }


}

void Assignment4Frame::OnPanel1Paint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    Draw(dc);
}

void Assignment4Frame::OnPanel1LeftDoubleClick(wxMouseEvent& event)
{
    if(DrawMode == false ){
        DrawMode = true;
        wxPaintDC dc(Panel1);
        Draw(dc);
    }else if(DrawMode == true){
        DrawMode = false;
        count = 0;
        Refresh();

    }
}

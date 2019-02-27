/***************************************************************
 * Name:      Assignment_4Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    silvio lupo ()
 * Created:   2019-02-17
 * Copyright: silvio lupo ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Assignment_4Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Assignment_4Frame)
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

//(*IdInit(Assignment_4Frame)
const long Assignment_4Frame::ID_PANEL1 = wxNewId();
const long Assignment_4Frame::idMenuQuit = wxNewId();
const long Assignment_4Frame::idMenuAbout = wxNewId();
const long Assignment_4Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Assignment_4Frame,wxFrame)
    //(*EventTable(Assignment_4Frame)
    //*)
END_EVENT_TABLE()

Assignment_4Frame::Assignment_4Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Assignment_4Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(208,264), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
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

    Panel1->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Assignment_4Frame::OnPanel1LeftDown,0,this);
    Panel1->Connect(wxEVT_LEFT_DCLICK,(wxObjectEventFunction)&Assignment_4Frame::OnPanel1LeftDClick,0,this);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Assignment_4Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Assignment_4Frame::OnAbout);
    //*)
}

Assignment_4Frame::~Assignment_4Frame()
{
    //(*Destroy(Assignment_4Frame)
    //*)
}

void Assignment_4Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Assignment_4Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));

}

 void Assignment_4Frame::Click()
 {

    wxClientDC dc(Panel1);
    dc.SetBrush(*wxBLACK_BRUSH);
    dc.SetPen( wxPen( wxColor (0,0,0),2) );

    dc.DrawCircle( points[arr_length], 2  );

}

void Assignment_4Frame::OnPanel1LeftDown(wxMouseEvent& event)
{
    if (arr_length < 100){
        points[arr_length] = event.GetPosition();
        Click ();
        arr_length++;

    }
    else {
    }

}

void Assignment_4Frame::OnPanel1LeftDClick(wxMouseEvent& event)
{
    if (mode==0){
            mode = 1;
    }

    Draw();
    mode=2;
}

void Assignment_4Frame::Draw(){



    if (mode==1){

    wxClientDC dc(Panel1);
    dc.SetBrush(*wxBLACK_BRUSH);
    dc.SetPen( wxPen( wxColor (0,0,0),2) );
    dc.DrawLines(arr_length, points);

    }

    else if (mode==2){

        wxClientDC dc(Panel1);
        dc.Clear();

        dc.SetBrush(*wxBLACK_BRUSH);
        dc.SetPen( wxPen( wxColor (0,0,0),2) );
        dc.DrawLines(arr_length, points);


    }

        arr_length=0;
        mode=0;



//    dc.DrawCircle( wxPoint(200,100) , 2  );
}


/***************************************************************
 * Name:      Assignment4Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-02-18
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef ASSIGNMENT4MAIN_H
#define ASSIGNMENT4MAIN_H

//(*Headers(Assignment4Frame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
//*)

class Assignment4Frame: public wxFrame
{
    public:

        Assignment4Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Assignment4Frame();

    private:

        //(*Handlers(Assignment4Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPanel1LeftDClick(wxMouseEvent& event);
        void OnPanel1LeftDoubleClick1(wxMouseEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnPanel1LeftDoubleClick(wxMouseEvent& event);
        //*)

        //(*Identifiers(Assignment4Frame)
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Assignment4Frame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ASSIGNMENT4MAIN_H

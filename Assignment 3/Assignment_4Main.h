/***************************************************************
 * Name:      Assignment_4Main.h
 * Purpose:   Defines Application Frame
 * Author:    silvio lupo ()
 * Created:   2019-02-17
 * Copyright: silvio lupo ()
 * License:
 **************************************************************/

#ifndef ASSIGNMENT_4MAIN_H
#define ASSIGNMENT_4MAIN_H

//(*Headers(Assignment_4Frame)
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
//*)

class Assignment_4Frame: public wxFrame
{
    public:

        Assignment_4Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Assignment_4Frame();

    private:

        //(*Handlers(Assignment_4Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPanel1LeftDown(wxMouseEvent& event);
        void OnPanel1LeftDClick(wxMouseEvent& event);
        //*)

        //(*Identifiers(Assignment_4Frame)
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Assignment_4Frame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        //*)

        void Click();
        void Draw();
        wxPoint points[100];
        int arr_length;
        int mode;

        DECLARE_EVENT_TABLE()
};

#endif // ASSIGNMENT_4MAIN_H

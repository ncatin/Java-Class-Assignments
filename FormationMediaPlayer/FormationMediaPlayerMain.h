/***************************************************************
 * Name:      FormationMediaPlayerMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-10-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef FORMATIONMEDIAPLAYERMAIN_H
#define FORMATIONMEDIAPLAYERMAIN_H

//(*Headers(FormationMediaPlayerFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
//*)

class FormationMediaPlayerFrame: public wxFrame
{
    public:

        FormationMediaPlayerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~FormationMediaPlayerFrame();

    private:

        //(*Handlers(FormationMediaPlayerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnImportMusic(wxCommandEvent& event);
        void OnPlayButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(FormationMediaPlayerFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_SLIDER1;
        static const long ID_TEXTCTRL1;
        static const long idMenuImport;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(FormationMediaPlayerFrame)
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxButton* Button2;
        wxMenuItem* MenuItem3;
        wxTextCtrl* TextCtrl1;
        wxSlider* Slider1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // FORMATIONMEDIAPLAYERMAIN_H

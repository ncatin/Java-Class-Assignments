/***************************************************************
 * Name:      Tic_Tac_ToeMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-07-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef TIC_TAC_TOEMAIN_H
#define TIC_TAC_TOEMAIN_H

//(*Headers(Tic_Tac_ToeFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Tic_Tac_ToeFrame: public wxFrame
{
    public:

        Tic_Tac_ToeFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Tic_Tac_ToeFrame();

    private:

        //(*Handlers(Tic_Tac_ToeFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnPanel1LeftDClick(wxMouseEvent& event);
        //*)

        //(*Identifiers(Tic_Tac_ToeFrame)
        static const long ID_PANEL1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Tic_Tac_ToeFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxTextCtrl* TextCtrl1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TIC_TAC_TOEMAIN_H

/***************************************************************
 * Name:      Tic_Tac_ToeApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2019-07-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Tic_Tac_ToeApp.h"

//(*AppHeaders
#include "Tic_Tac_ToeMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Tic_Tac_ToeApp);

bool Tic_Tac_ToeApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Tic_Tac_ToeFrame* Frame = new Tic_Tac_ToeFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

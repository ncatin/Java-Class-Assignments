/***************************************************************
 * Name:      Assignment4App.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2019-02-18
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Assignment4App.h"

//(*AppHeaders
#include "Assignment4Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Assignment4App);

bool Assignment4App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Assignment4Frame* Frame = new Assignment4Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

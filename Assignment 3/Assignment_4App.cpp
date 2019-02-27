/***************************************************************
 * Name:      Assignment_4App.cpp
 * Purpose:   Code for Application Class
 * Author:    silvio lupo ()
 * Created:   2019-02-17
 * Copyright: silvio lupo ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Assignment_4App.h"

//(*AppHeaders
#include "Assignment_4Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Assignment_4App);

bool Assignment_4App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Assignment_4Frame* Frame = new Assignment_4Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        
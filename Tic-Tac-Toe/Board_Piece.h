#include <wx/gdicmn.h>

#ifndef BOARD_PIECE_H
#define BOARD_PIECE_H

class Board_Piece{
public:
    wxRect* area;
    char XO;
    int x, y, x1, y1;
    bool taken;


    Board_Piece(int x, int y, int x1, int y1){
        area = new wxRect(wxPoint(x,y),wxPoint(x1,y1));
        this->x = x;
        this->y = y;
        this->x1 = x1;
        this->y1 = y1;
    }

    bool Contains(wxPoint pnt){
        return area->Contains(pnt);
    }

    void DrawXO(wxClientDC& dc){

        dc.DrawLine(wxPoint(x,y),wxPoint(x1,y1));
        dc.DrawLine(wxPoint(x+100,y),wxPoint(x1-100,y1));

        XO = 'X';
        taken = true;
    }

    void RandomO(wxClientDC& dc){
        dc.DrawCircle(wxPoint((x+x1)/2,(y+y1)/2), 40);
        dc.SetBrush(*wxWHITE_BRUSH);
        dc.DrawCircle(wxPoint((x+x1)/2,(y+y1)/2), 37);
        XO = 'O';
        taken = true;
    }

    ~Board_Piece(){
        delete area;
    }

};

#endif // BOARD_PIECE_H

#include <wx/gdicmn.h>

#ifndef BOARD_H
#define BOARD_H

class Board{
public:
    Board_Piece* BoardArr[9];
    int player, numTaken;
    bool GameOver;

    Board(){
            BoardArr[0] = new Board_Piece(0,0,100,100);
            BoardArr[1] = new Board_Piece(100,0,200,100);
            BoardArr[2] = new Board_Piece(200,0,300,100);
            BoardArr[3] = new Board_Piece(0,100,100,200);
            BoardArr[4] = new Board_Piece(100,100,200,200);
            BoardArr[5] = new Board_Piece(200,100,300,200);
            BoardArr[6] = new Board_Piece(0,200,100,300);
            BoardArr[7] = new Board_Piece(100,200,200,300);
            BoardArr[8] = new Board_Piece(200,200,300,300);

            player = 1;
            numTaken = 0;
            GameOver = false;

    }

    int CheckWin(){
        if(BoardArr[0]->XO == BoardArr[1]->XO && BoardArr[1]->XO == BoardArr[2]->XO){
            if(BoardArr[0]->XO == 'X'){
              GameOver = true;
              return 1;
            }
            else if(BoardArr[0]->XO == 'O'){
              GameOver = true;
              return 2;
            }
        }else if(BoardArr[3]->XO == BoardArr[4]->XO && BoardArr[4]->XO == BoardArr[5]->XO){
            if(BoardArr[3]->XO == 'X'){
                GameOver = true;
                return 1;
            }
            else if(BoardArr[3]->XO == 'O'){
                GameOver = true;
                return 2;
            }
        }else if(BoardArr[6]->XO == BoardArr[7]->XO && BoardArr[7]->XO == BoardArr[8]->XO){
            if(BoardArr[6]->XO == 'X'){
                GameOver = true;
                return 1;
            }
            else if(BoardArr[6]->XO == 'O'){
                GameOver = true;
                return 2;
            }
        }else if(BoardArr[0]->XO == BoardArr[3]->XO && BoardArr[3]->XO == BoardArr[6]->XO){
            if(BoardArr[0]->XO == 'X'){
                GameOver = true;
                return 1;
            }
            else if(BoardArr[0]->XO == 'O'){
                GameOver = true;
                return 2;
            }
        }else if(BoardArr[1]->XO == BoardArr[4]->XO && BoardArr[4]->XO == BoardArr[7]->XO){
            if(BoardArr[1]->XO == 'X'){
                GameOver = true;
                return 1;
            }
            else if(BoardArr[1]->XO == 'O'){
                GameOver = true;
                return 2;
            }
        }else if(BoardArr[2]->XO == BoardArr[5]->XO && BoardArr[5]->XO == BoardArr[8]->XO){
            if(BoardArr[2]->XO == 'X'){
                GameOver = true;
                return 1;
            }
            else if(BoardArr[2]->XO == 'O'){
                GameOver = true;
                return 2;
            }
        }else if(BoardArr[0]->XO == BoardArr[4]->XO && BoardArr[4]->XO == BoardArr[8]->XO){
            if(BoardArr[0]->XO == 'X'){
                GameOver = true;
                return 1;
            }
            else if(BoardArr[0]->XO == 'O'){
                GameOver = true;
                return 2;
            }
        }else if(BoardArr[2]->XO == BoardArr[4]->XO && BoardArr[4]->XO == BoardArr[6]->XO){
            if(BoardArr[2]->XO == 'X'){
                GameOver = true;
                return 1;
            }
            else if(BoardArr[2]->XO == 'O'){
                GameOver = true;
                return 2;
            }
        }
    }

    void Click(wxPoint point, wxClientDC& dc){
        //int AI = rand()%9;

        for(int x = 0; x < 9; x++){
            if(BoardArr[x]->Contains(point) && !BoardArr[x]->taken)
                if(player == 1){
                    BoardArr[x]->DrawXO(dc);
                    player = 2;
                    numTaken ++;
                } else if(player ==2 ){
                    BoardArr[x]->RandomO(dc);
                    player = 1;
                    numTaken ++;
                }


        }

    }

    ~Board(){
        delete[] BoardArr;
    }
};

#endif // BOARD_H

//Nicholas Catin 3891183

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include "cell.h"

using namespace std;

Cell**** MyArray;

void print2D(Cell **Array[], int d1, int d2){
    for(int x = 0; x < d1; x++){
        printf("\n");
        for(int y=0; y<d2; y++){
            if(Array[x][y] == nullptr)
                cout << "[ ]";
            else
                cout << "[*]";
        }
    }
    printf("\n");
}

void tick2D(Cell **Array[], int d1, int d2){
    for(int x = 0; x < d1; x++){
        for(int y=0; y<d2; y++){
            if(Array[x][y] != nullptr)
                Array[x][y]->tick();
        }
    }
}

int main(int argc, char *argv[]){
    int d1 = atoi(argv[1]);
    //int d1 = 5;
    int d2 = atoi(argv[2]);
    //int d2 = 5;
    int d3 = atoi(argv[3]);
    //int d3 = 5;

    int index1,index2,index3;

    MyArray = new Cell*** [d1];

    for(index1=0; index1 < d1; index1++){
        MyArray[index1] = new Cell **[d2];
        for( index2=0; index2 < d2; index2++){
            MyArray[index1][index2] = new Cell*[d3];
        }

    }


    for(index1=0; index1 < d1; index1++){
            for(index2=0; index2 < d2; index2++){
                for(index3=0; index3 < d3; index3++){
                    MyArray[index1][index2][index3] = nullptr;
                }

            }

        }

    MyArray[2][2][2] = new Cell(2,2,2);
    MyArray[1][1][1] = new Cell(1,1,1);
    MyArray[0][0][0] = new Cell(0,0,0);

    for(int x = 0; x < d1; x++){
            printf("%d", x);
            print2D(MyArray[x], d2, d3);
    }

    for(int x = 0; x < d1; x++){
            tick2D(MyArray[x], d2, d3);
    }

    for(index1=0; index1 < d1; index1++){
       for( index2=0; index2 < d2; index2++){
           delete[] MyArray[index1][index2] ;
        }
        delete[] MyArray[index1];
    }
    delete[] MyArray;


}

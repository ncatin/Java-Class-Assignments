#include "cell.h"
#include <iostream>
#include <stdlib.h>


using namespace std;

Cell::Cell(){
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;

    fAry[0] = f1;
    fAry[1] = f2;
    fAry[2] = f3;

    IsInit = true;


}

Cell::Cell(int x, int y, int z){
    pos.x = x;
    pos.y = y;
    pos.z = z;

    fAry[0] = f1;
    fAry[1] = f2;
    fAry[2] = f3;

    IsInit = true;

}

void Cell::tick(){
    cout << "Cell(" << pos.x << "," << pos.y << "," << pos.z << ")" << " ";
    int r = rand() % 3;
    fAry[r]();
    cout << "\n";
}

void Cell::f1(){
    cout << "f1";
}

void Cell::f2(){
    cout << "f2";
}

void Cell::f3(){
    cout << "f3";
}

Cell::~Cell(){
    delete[] fAry;

}

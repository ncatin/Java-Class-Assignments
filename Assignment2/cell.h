#include <iostream>
#ifndef CELL_H
#define CELL_H

struct loc{int x; int y; int z;};
typedef struct loc location;
typedef void (*fptr)(void);

class Cell{
public:
    location pos;
    bool IsInit;
    void tick();
    Cell();
    Cell(int x,int y,int z);
    ~Cell();
private:
    static void f1(void);
    static void f2(void);
    static void f3(void);

    fptr fAry[3];


};
#endif // CELL_H

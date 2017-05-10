#ifndef RETA_H
#define RETA_H

#include "figurageometrica.h"

class Reta: public FiguraGeometrica{
public:
    Reta();
    void draw(Screen &t);
    void setXY0(int x0, int y0);
    void setXY1(int x1, int y1);
private:
    int x0,y0,x1,y1;
};

#endif // RETA_H

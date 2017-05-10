#ifndef CIRCULO_H
#define CIRCULO_H

#include "figurageometrica.h"

class Circulo: public FiguraGeometrica{
public:
    Circulo();
    void draw(Screen &t);
    void setXY(int x, int y);
    void setR(int r);
    int getX();
    int getY();
    int getR();

 private:
    int x,y; //centro do círculo
    int r; //raio
};

#endif // CIRCULO_H

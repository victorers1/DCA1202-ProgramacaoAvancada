#ifndef CIRCULO_H
#define CIRCULO_H

#include "figurageometrica.h"

class Circulo: public FiguraGeometrica{
public:
    Circulo(int x, int y, int r, int p);
    void draw(Screen &t);
    int getX();
    int getY();
    int getR();
    int getP();

 private:
    int x,y; //centro do círculo
    int r; //raio
    bool preenchimento; //fillmode
};

#endif // CIRCULO_H

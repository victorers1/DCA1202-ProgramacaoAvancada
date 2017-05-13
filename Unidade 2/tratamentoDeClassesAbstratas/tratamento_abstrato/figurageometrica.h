#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "screen.h"

class FiguraGeometrica{ //não pode instanciar objetos
public:
    FiguraGeometrica();
    virtual void draw(Screen &t)=0; //classes herdeiras são obrigadas a implementar essa função
    void setBrush();
    char getBrush();
private:
    char brush;
};

#endif // FIGURAGEOMETRICA_H

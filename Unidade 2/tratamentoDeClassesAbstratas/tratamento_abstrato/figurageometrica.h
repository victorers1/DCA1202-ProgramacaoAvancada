#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "screen.h"

class FiguraGeometrica{ //não pode instanciar objetos
public:
    FiguraGeometrica();
    virtual void draw()=0; //classes herdeiras são obrigadas a implementar essa função
};

#endif // FIGURAGEOMETRICA_H

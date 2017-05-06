#ifndef RETANGULO_H
#define RETANGULO_H

#include "figurageometrica.h"

class Retangulo : public FiguraGeometrica{
public:
    Retangulo();
    virtual void draw()=0;
};

#endif // RETANGULO_H

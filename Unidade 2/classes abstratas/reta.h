#ifndef RETA_H
#define RETA_H

#include "figurageometrica.h"

class Reta : public FiguraGeometrica{
public:
    Reta();
    void draw();
    int area();//um ponteiro para FiguraGeometrica não tem acesso à esta função
};

#endif // RETA_H

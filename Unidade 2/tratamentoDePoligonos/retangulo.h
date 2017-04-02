#ifndef RETANGULO_H
#define RETANGULO_H
#include "poligono.h"

class Retangulo: public Poligono {
public:
    Retangulo();
    ~Retangulo();
    Retangulo(float x, float y, float largura, float altura);

private:
    float l, h; //largura e altura
};

#endif // RETANGULO_H

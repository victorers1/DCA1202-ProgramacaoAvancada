#ifndef RETANGULO_H
#define RETANGULO_H

#include "figurageometrica.h"

class Retangulo: public FiguraGeometrica{
public:
    Retangulo();
    void draw(Screen &t);
    void setLA(int l, int a); //define largura e altura
    void setXY(int x, int y);
    int getX();
    int getY();
    int getL(); //recupera valor da largura
    int getA(); //recupera valor da altura
private:
    int l, a; //largura, altura
    int x, y; //coordenadas do vértice superior esquerdo
};

#endif // RETANGULO_H

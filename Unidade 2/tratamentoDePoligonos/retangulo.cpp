#include <iostream>
#include "point.h"
#include "poligono.h"
#include "retangulo.h"

Retangulo::Retangulo(float x, float y, float largura, float altura){
    l = largura;
    h = altura;
    nVert = 4;

    Point p[nVert]; //vetor de pontos

    p[0].setXY(x, y);         //superior esquerdo
    p[1].setXY(x, y - h);     //inferior esquerdo
    p[2].setXY(x + l, y - h); //inferior direito
    p[3].setXY(x + l, y);     //superior direito
}

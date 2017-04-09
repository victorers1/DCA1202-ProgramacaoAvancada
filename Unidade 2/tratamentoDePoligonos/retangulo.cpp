#include <iostream>
#include "point.h"
#include "poligono.h"
#include "retangulo.h"

using namespace std;

Retangulo::Retangulo(){
    delete p;
    p = new Point[4];
    //cout<<"Retangulo criado\n";
}

Retangulo::~Retangulo(){
    delete p;
    //cout<<"Retangulo destruído\n";
}

Retangulo::Retangulo(float x, float y, float largura, float altura){
    delete p;
    p = new Point[4];
    //cout<<"Retangulo criado\n";
    l = largura;
    h = altura;
    //nVert = 4;
    //cada addVertice() excecuta um nVert++;
    addVertice(x,y);
    addVertice(x, y-h);
    addVertice(x+l, y-h);
    addVertice(x+l, y);
}

float Retangulo::area(){
    return l*h;
}

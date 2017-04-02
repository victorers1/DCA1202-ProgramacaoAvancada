#include <iostream>
#include "point.h"
#include "poligono.h"
#include "retangulo.h"

using namespace std;

Retangulo::Retangulo(){
    //cout<<"Ponto criad\no";
}

Retangulo::~Retangulo(){
    //cout<<"Retangulo destruído\n";
}

Retangulo::Retangulo(float x, float y, float largura, float altura){
    l = largura;
    h = altura;
    nVert = 4; //muito importante fixar número de pontos devido a função imprimir();

    //os pontos poderiam ser adicionados sem funções, pois são apenas "Protected" na classe Polígono
    p[0].setXY(x, y);         //superior esquerdo
    p[1].setXY(x, y - h);     //inferior esquerdo
    p[2].setXY(x + l, y - h); //inferior direito
    p[3].setXY(x + l, y);     //superior direito
}

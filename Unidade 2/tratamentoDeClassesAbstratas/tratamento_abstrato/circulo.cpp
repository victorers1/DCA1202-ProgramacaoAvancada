#include "circulo.h"
#include <cmath>
#include <iostream>

using namespace std;
Circulo::Circulo(int x, int y, int r, int p){
    if(r>=0){
        this->r = r;
        this->x = x;
        this->y = y;
        preenchimento = p;
    }else{
        throw "raio deve ser positivo";
    }
}

void Circulo::draw(Screen &t){
    int i,j=0;
    float dist; //distancia entre dois pontos
    if(preenchimento==0){ //sem preenchimento
        for(i=0; i<t.getLin(); i++){
            for(j=0; j<t.getCol(); j++){
                dist = sqrt(pow(i-x, 2) + pow(j-y, 2));
                //ceil(dist) == r || floor(dist) == r
                if(ceil(dist) == r ){ //verifica se a distancia entre o ponto (i,j) e o centro do circulo é próxima ao raio
                    t.setPixel(i,j);
                }
            }
        }
    } else {
        for(i=0; i<t.getLin(); i++){
            for(j=0; j<t.getCol(); j++){
                if(sqrt(pow(i-x, 2) + pow(j-y, 2)) <= r){ //verifica se a distancia entre o ponto (i,j) e o centro do circulo é menor ou igual ao raio
                    t.setPixel(i,j);
                }
            }
        }
    }
}

int Circulo::getX(){
    return x;
}

int Circulo::getY(){
    return y;
}

int Circulo::getR(){
    return r;
}


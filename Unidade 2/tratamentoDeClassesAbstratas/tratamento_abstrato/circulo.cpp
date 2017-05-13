#include "circulo.h"

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


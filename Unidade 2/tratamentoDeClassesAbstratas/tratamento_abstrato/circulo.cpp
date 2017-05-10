#include "circulo.h"

Circulo::Circulo(){

}

void Circulo::draw(Screen &t){

}

void Circulo::setXY(int x, int y){
    this->x = x;
    this->y = y;
}

void Circulo::setR(int r){
    if(r>=0){
        this->r = r;
    }else{
        throw "raio deve ser positivo";
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


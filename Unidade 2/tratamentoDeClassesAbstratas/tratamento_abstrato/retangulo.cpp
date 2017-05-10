#include "retangulo.h"

Retangulo::Retangulo(){

}

void Retangulo::draw(Screen &t){

}

void Retangulo::setLA(int l, int a){
    if(l>0 && a>0){
        this->l = l;
        this->a = a;
    }else{
        throw "largura e altura devem ser ambos maior que 0";
    }
}

void Retangulo::setXY(int x, int y){
    this->x = x;
    this->y = y;
}

int Retangulo::getX(){
    return x;
}

int Retangulo::getY(){
    return y;
}

int Retangulo::getL(){
    return l;
}

int Retangulo::getA(){
    return a;
}

#include "retangulo.h"
#include <iostream>

using namespace std;
Retangulo::Retangulo(int x, int y, int l, int a){
    if(l>0 && a>0){
        this->l = l;
        this->a = a;
        this->x = x;
        this->y = y;
    }else{
        throw "largura e altura devem ser ambos maior que 0";
    }
}

void Retangulo::draw(Screen &t){
    for(int i=y; i<a+y; i++){ //percorre screen de y até y+a
        for(int j=x; j<l+x; j++){ //percorre screen de x até x+l
            t.setPixel(i,j);
        }
    }
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

#include "reta.h"

Reta::Reta(){

}

void Reta::draw(Screen &t){

}

void Reta::setXY0(int x0, int y0){
    if(this->x0 != x1 && this->y0 != y1){
        this->x0 = x0;
        this->y0 = y0;
    }
}

void Reta::setXY1(int x1, int y1){
    if(this->x1 != x0 && this->y1 != y0){
        this->x1 = x1;
        this->y1 = y1;
    }
}

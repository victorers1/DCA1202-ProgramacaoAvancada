#include "reta.h"

Reta::Reta(int x0,int y0, int x1,int y1){
    if(this->x0 != this->x1 && this->y0 != this->y1){
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    } else{
        throw "foram inseridos dois pontos iguais";
    }
}

void Reta::draw(Screen &t){
    for(float i=0.0; (int)i < 1; i+=0.1){

    }
}
/*P0 = (x0, y0)
 *v = (a, b) = (P1 - P0)
 *
 *x = x0 + t*a
 *y = y0 + t*b
*/

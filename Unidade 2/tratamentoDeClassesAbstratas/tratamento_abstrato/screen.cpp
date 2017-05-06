#include "screen.h"
#include <vector>

Screen::Screen(int nlin, int ncol){
    this->nlin = nlin;
    this->ncol = ncol;
}

void Screen::setPixel(int x, int y){
    mat[x][y] = brush;
}

void Screen::clear(){

}

void Screen::setBrush(char brush){
    this->brush = brush;
}

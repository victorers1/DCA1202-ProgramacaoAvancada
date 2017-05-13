#include "screen.h"
#include <vector>

Screen::Screen(){

}

void Screen::dim(int x, int y){
    int i,j;
    this->nlin = nlin;
    this->ncol = ncol;
    //dimencionando mat
    mat.resize(x);
    for(i=0; i<x; i++){
        mat[i].resize(y);
    }

    //preenchimento inicial
    for(i=0; i<x; i++){
        for(j=0; j<y; j++){
            mat[i][j] = ' '; //espaços vazios
        }
    }
}

void Screen::setPixel(int x, int y){
    mat[x][y] = brush;
}

void Screen::clear(){
    for(int i=0; i<nlin; i++){
        for(int j=0; j<ncol; j++){
            mat[i][j] = ' ';
        }
    }
}

void Screen::setBrush(char brush){
    this->brush = brush;
}

ostream &operator<<(ostream &os, Screen &t){
    for(int i=0; i<t.nlin; i++){
        for(int j=0; j<t.ncol; j++){
            os<<t.mat[i][j]<<' ';
        }
        os<<endl;
    }
}

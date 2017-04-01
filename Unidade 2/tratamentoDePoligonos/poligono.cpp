#include <iostream>
#include "point.h"
#include "poligono.h"

using namespace std;

void Poligono::addVertice(Point p1){
    p[(int)nVert++] = p1;
    cout<<"Criado vetor "<<(int)(nVert-1) << " coordenadas: ";
    p[(int)nVert].imprime();
    cout<<"\n\n";
}

void Poligono::removeVertice(){
    nVert--;
}

int Poligono::getNumVertice(){
    return nVert;
}

float Poligono::area(){
    float soma1=0.0, soma2=0.0;
    for(int i=0; i<nVert; i++){
        soma1 += (p[i].getX() * p[i+1].getY());
        soma2 += (p[i].getY() * p[i+1].getX());
    }

    return (soma1 - soma2)/2;
}

void Poligono::translada(float a, float b){
    for(int i=0; i<nVert; i++){
        p[i].translada(a,b); //soma todos os vértices ao ponto (a,b)
    }
}

void Poligono::rotaciona(Point p1, float ang){

}

void Poligono::imprimir(){
    for(int i=0; i<nVert; i++){
        p[i].imprime();
        if(i<(nVert-1)){ //não precisa de seta no último elemento
            cout<<"->";
        }
    }
}

#include <iostream>
#include <cmath>
#include "point.h"
#include "poligono.h"

#define PI 3.14159265

using namespace std;

Poligono::Poligono(){
    //cout<<"Poligono criado\n";
}

Poligono::~Poligono(){
    //cout<<"Poliogono destruído\n";
}

void Poligono::addVertice(Point p1){
    p[(int)nVert++] = p1;
    cout<<"Criado vetor "<<(int)(nVert-1) << " coordenadas: ";
    p[(int)nVert].imprime();
    cout<<"\n\n";
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

    return (soma1 - soma2)/2; //média das somas
}

void Poligono::translada(float a, float b){
    for(int i=0; i<nVert; i++){
        p[i].translada(a,b); //soma todos os vértices ao ponto (a,b)
    }
}

void Poligono::rotaciona(Point p1, float ang){
    float c = cos(ang*PI/180.0);
    float s = sin(ang*PI/180.0);

    for(int i=0; i<nVert; i++){
        p[i].setX(p1.getX() + (p[i].getX()-p1.getX())*c - (p[i].getY()-p1.getY())*s);
        p[i].setY(p1.getY() + (p[i].getX()-p1.getX())*c + (p[i].getY()-p1.getY())*s);
    }
}

void Poligono::imprimir(){
    int i=0;
    for(i=0; i<nVert-1; i++){
        p[i].imprime();
        cout<<" -> ";
    }
    p[i].imprime();
}

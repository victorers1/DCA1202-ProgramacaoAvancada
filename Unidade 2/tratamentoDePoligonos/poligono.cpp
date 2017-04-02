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
    p[nVert++] = p1;
    cout<<"Criado vetor "<<(int)(nVert-1) << " coordenadas: ";
    p[nVert-1].imprime();
    cout<<"\n\n";
}

void Poligono::addVertice(float mx, float my){
    p[nVert].setX(mx);
    p[nVert++].setY(my);
    cout<<"Criado vertice "<<(nVert-1) << " coordenadas: ";
    p[nVert-1].imprime();
    cout<<"\n\n";
}

int Poligono::getNumVertice(){
    return nVert;
}

float Poligono::area(){
    float A=0.0;
    for(int i=0; i<nVert-1; i++){
        A += (p[i].getX()*p[i+1].getY() - p[i+1].getX()*p[i].getY());
    }
    //agora opera os pontos  da última aresta: p[nVert] e p[0]
    A += (p[nVert-1].getX()*p[0].getY() - p[0].getX()*p[nVert-1].getY());
    return (A/2);
}

void Poligono::translada(float a, float b){
    for(int i=0; i<nVert; i++){
        p[i].translada(a,b); //soma todos os vértices ao ponto (a,b)
    }
}

/*
novoX = centroX + (pontoX - centroX) * Math.cos(angulo) - (pontoY - centroY) * Math.sin(angulo);
novoY = centroY + (pontoX - centroX) * Math.sin(angulo) + (pontoY - centroY) * Math.cos(angulo);
*/
void Poligono::rotaciona(Point p1, float ang){
    float c = cos(ang*PI/180.0);
    float s = sin(ang*PI/180.0);

    for(int i=0; i<nVert; i++){
        p[i].setX(p1.getX() + ((p[i].getX()-p1.getX())*c - (p[i].getY()-p1.getY())*s));
        p[i].setY(p1.getY() + ((p[i].getX()-p1.getX())*c + (p[i].getY()-p1.getY())*s));
    }
}

void Poligono::imprime(){
    int i=0;
    for(i=0; i<nVert; i++){
        p[i].imprime();
        cout<<" -> ";
    }
    p[0].imprime();
}

Point Poligono::centroide(){
    float cx=0.0,cy=0.0;
    for(int i=0; i<nVert-1; i++){
        cx += (p[i].getX() + p[i+1].getX())*(p[i].getX() * p[i+1].getY() - p[i+1].getX() * p[i].getY());
        cy += (p[i].getY() + p[i+1].getY())*(p[i].getX() * p[i+1].getY() - p[i+1].getX() * p[i].getY());
    }
    //próxima iteração deve ser com o primeiro e último ponto: p[nVert-1] e p[0]
    cx += (p[nVert-1].getX() + p[0].getX())*(p[nVert-1].getX() * p[0].getY() - p[0].getX() * p[nVert-1].getY());
    cy += (p[nVert-1].getY() + p[0].getY())*(p[nVert-1].getX() * p[0].getY() - p[0].getX() * p[nVert-1].getY());

    cx = cx/(6.0*area());
    cy = cy/(6.0*area());
    Point centro(cx, cy);
    return centro;
}

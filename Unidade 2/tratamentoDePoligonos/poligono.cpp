#include <iostream>
#include <cmath>
#include "point.h"
#include "poligono.h"

#define RAD 0.01745329251994329576923690768489 //PI/180.0
#define PI 3.1415926535897932384626433832795
using namespace std;

Poligono::Poligono(){
    p = new Point[100];
    //cout<<"Poligono criado\n";
}

Poligono::~Poligono(){
    delete [] p;
    //cout<<"Poligono destruído\n";
}

void Poligono::addVertice(Point p1){
    p[nVert++] = p1;
    p[nVert-1].imprime();
    cout<<"\n\n";
}

void Poligono::addVertice(float mx, float my){
    p[nVert].setX(mx);
    p[nVert++].setY(my);
}

int Poligono::getNumVertice(){
    return nVert;
}

float Poligono::area(){
    float A=0.0;
    for(int i=0; i<nVert-1; i++){
        A += (p[i].getX()*p[i+1].getY() - p[i+1].getX()*p[i].getY());
    }
    //agora opera os pontos da última aresta: p[nVert] e p[0]
    A += (p[nVert-1].getX()*p[0].getY() - p[0].getX()*p[nVert-1].getY());
    return (A/2);
}

void Poligono::translada(float a, float b){
    for(int i=0; i<nVert; i++){
        p[i].translada(a,b); //soma todos os vértices ao ponto (a,b)
    }
}

/*Fórmula da rotação
novoX = centroX + (pontoX - centroX) * Math.cos(angulo) - (pontoY - centroY) * Math.sin(angulo);
novoY = centroY + (pontoX - centroX) * Math.sin(angulo) + (pontoY - centroY) * Math.cos(angulo);
*/

/*
 * Rotaciona o polígono no sentido:
 * anti-horário, se angulo >0
 * horário, se angulo <0
*/
void Poligono::rotaciona(Point eixo, float ang){
    float c = cos(ang*PI/(float)180.0);
    float s = sin(ang*PI/(float)180.0);
    float xPonto ,yPonto, xEixo, yEixo;

    for(int i=0; i<nVert; i++){
        xPonto = p[i].getX(); yPonto = p[i].getY();
        xEixo = eixo.getX(); yEixo = eixo.getY();

        p[i].setX(xEixo + c*(xPonto - xEixo) - s*(yPonto - yEixo));
        p[i].setY(yEixo + s*(xPonto - xEixo) + c*(yPonto - yEixo));
    }
}

void Poligono::rotaciona(float xc, float yc, float ang){
    float c = cos(ang*PI/(float)180);
    float s = sin(ang*PI/(float)180);
    float xPonto ,yPonto;

    for(int i=0; i<nVert; i++){
        xPonto = p[i].getX(); yPonto = p[i].getY();

        p[i].setX(xc + c*(xPonto - xc) - s*(yPonto - yc));
        p[i].setY(yc + s*(xPonto - xc) + c*(yPonto - yc));
    }
}

void Poligono::imprime(){
    for(int i=0; i<nVert; i++){
        p[i].imprime();
        cout<<" -> ";
    }
    p[0].imprime();//fecha polígono
}

Point Poligono::centroide(){
    float cx=0.0, cy=0.0, x0=0.0, y0=0.0, x1=0.0, y1=0.0;
    float seisArea = 6*area();
    for(int i=0; i<nVert-1; i++){
        x0 = p[i].getX(); y0 = p[i].getY(); //ponto atual
        x1 = p[i+1].getX(); y1 = p[i+1].getY(); //próximo ponto

        cx += (x0 + x1)*(x0 * y1 - x1 * y0);
        cy += (y0 + y1)*(x0 * y1 - x1 * y0);
    }

    //próxima iteração deve ser com o primeiro e último ponto: p[nVert-1] e p[0]
    x0 = p[nVert-1].getX(); y0 = p[nVert-1].getY();
    x1 = p[0].getX(); y1 = p[0].getY();

    cx += (x0 + x1)*(x0 * y1 - x1 * y0);
    cy += (y0 + y1)*(x0 * y1 - x1 * y0);

    cx = cx/seisArea;//o uso da variável seisArea alivia a chamada de duas funções
    cy = cy/seisArea;
    Point centro(cx, cy);
    return centro;
}

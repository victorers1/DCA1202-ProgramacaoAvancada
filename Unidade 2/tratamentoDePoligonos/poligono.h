#ifndef POLIGONO_H
#define POLIGONO_H
#include "point.h"

class Poligono{
public:
    Poligono();
    ~Poligono();
    void addVertice(Point p1);//insere novo ponto no polígono, assumindo que eles são inseridos em sentido anti-horário
    void addVertice(float mx, float my);
    int getNumVertice(); // retorna o número de pontos do polígono
    float area(); //Calcula a área. Esta é uma função virtual, deve ser implementada pelas classes herdeiras
    void translada(float a, float b); //move cada vértice do polígono para o ponto (x+a,y+b)
    void rotaciona(Point eixo, float ang); //rotaciona o polígono em "ang" graus em torno do ponto p1
    void rotaciona(float xc, float yc, float ang);
    void imprime();
    Point centroide();

protected: //protected significa que as subclasses podem acessá-los como se fossem seus atributos
    Point *p;
    int nVert=0; // número de vértices, 0 <= nVert <= 100
};



#endif // POLIGONO_H

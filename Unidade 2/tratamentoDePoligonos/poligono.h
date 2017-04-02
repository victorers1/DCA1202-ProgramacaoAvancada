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
    float area(); //calcula a área
    void translada(float a, float b); //move o polígono para o ponto (a,b)
    void rotaciona(Point p1, float ang); //rotaciona o polígono em "ang" graus em torno do ponto p1
    void imprime();
    Point centroide();

protected: //protected significa que as subclasses podem acessá-los como se fossem seus atributos
    Point p[100];
    int nVert=0; // número de vértices, 0 <= nVert <= 100
};

#endif // POLIGONO_H

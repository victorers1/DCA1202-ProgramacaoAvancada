#include <iostream>
#include "point.h"
#include "poligono.h"
#include "retangulo.h"

using namespace std;

int main(){
    Point origem(0.0, 0.0);
    Point centro(0.0, 0.0);

    //Teste da classe Polígono
    Poligono pol;//cubo de lado igual raiz de 2
    pol.addVertice(0,0);
    pol.addVertice(1,1);
    pol.addVertice(0,2);
    pol.addVertice(-1, 1);
    cout<<"Cubo de lado=sqrt(2) criado: ";
    pol.imprime(); cout<<endl;
    cout<<"Area o cubo: " << pol.area() <<endl;
    cout<<"Cubo apos rotacao horaria de 45 graus em torno da origem: \n";
    pol.rotaciona(origem, -45);
    pol.imprime(); cout<<endl;
    cout<<"Area apos rotacao: " << pol.area() <<endl;

    cout<<"\n\n";

    //Teste da classe Retangulo
    Retangulo ret(origem.getX(), origem.getY(), 4, 3);

    cout<<"Retangulo: "; ret.imprime(); cout<<endl;
    cout<<"Area do retangulo: "<< ret.area() << endl;
    cout<<"Transladando retangulo em x+=0, y+=4 \n";
    ret.translada(-3, 4);
    cout<<"Coordendas do novo retangulo: \n";
    ret.imprime(); cout<<endl;
    cout<<"Area do novo retangulo: "<< ret.area()<< "\n";
    centro = ret.centroide();
    cout<<"Centroide do retangulo: ";
    centro.imprime(); cout<<endl;
    ret.rotaciona(centro, 90);
    cout<<"Rotacionado 90 graus em torno de seu centro: ";
    ret.imprime(); cout<<endl;
    cout<<"Area apos rotacao: "<< ret.area()<<endl;

    //TESTE SUGERIDO
    /*
    Retangulo r(0.0, 0.0, 4.0, 3.0);
    r.imprime(); cout<<"\n";
    cout<<"Area: "<< r.area() <<endl;
    r.translada(-3.0, 4.0);
    r.imprime(); cout<<endl;
    cout<<"Area: "<< r.area() <<endl;
    Point p = r.centroide();
    cout<<"centroide: "; p.imprime(); cout<<endl;
    r.rotaciona(p, 30);
    r.imprime(); cout<<"\n";
    cout<<"Area: "<< r.area()<<endl;
    return 0;
    */
}

#include <iostream>
#include "point.h"
#include "poligono.h"
#include "retangulo.h"

using namespace std;

int main(){
    //ETAPA 4 - Teste das classes

    Point origem(0.0, 0.0);
    Point centro(0.0, 0.0);
    Retangulo ret(origem.getX(), origem.getY(), 4, 4);

    cout<<"Retangulo criado: "; ret.imprime(); cout<<endl;
    cout<<"Area do retangulo: "<< ret.area()<< " metros quadrados" << endl;

    cout<<"Transladando retangulo em x+=0, y+=4 ...\n";
    ret.translada(0, 4);
    cout<<"Novo retangulo: "; ret.imprime(); cout<<endl;
    cout<<"Area do novo retangulo: "<< ret.area()<< "\n";
    centro = ret.centroide();
    cout<<"Centroide do retangulo: "; centro.imprime(); cout<<endl;
    ret.rotaciona(centro, 90);
    cout<<"Rotacionado em torno do centro: "; ret.imprime(); cout<<endl;
    cout<<"Area apos rotacao: "<< ret.area()<<endl;


    return 0;
}

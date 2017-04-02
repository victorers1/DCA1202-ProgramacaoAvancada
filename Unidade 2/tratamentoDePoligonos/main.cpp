#include <iostream>
#include "point.h"
#include "poligono.h"
#include "retangulo.h"

using namespace std;

int main(){
    //ETAPA 4 - Teste das classes
    Point origem(0,0);
    Retangulo r(origem.getX(), origem.getY(), 3.0, 4.0);
    cout<<"Retangulo criado: \n";
    r.imprimir(); cout<<endl;
    cout<<"Area de r: "<<r.area()<<"\n";

    r.rotaciona(origem, 90);
    cout<<"Apos rotacao: \n";
    r.imprimir(); cout<<endl;
    cout<<"Area de r: "<<r.area()<<"\n";

    r.translada(-3,4);
    cout<<"Depois da translacao: ";
    r.imprimir(); cout<<"\n\n";
    cout<<"Area de r: "<<r.area()<<"\n";

    return 0;
}

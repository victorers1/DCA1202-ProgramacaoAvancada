#include <iostream>
#include "lista.h"
#include "no.h"
using namespace std;

int main(){
    No<int> a(1), b(2), c(3), d(4), e(5);

    Lista<int> l(&a);

    l.AddFim(&b);
    l.AddFim(&c);
    l.AddFim(&d);
    l.AddFim(&e);

    cout<<"lista original\n";
    l.print();

    l.RemIni();

    cout<<"remove inicio\n";
    l.print();

    return 0;
}

#include <iostream>
#include "numcomplex.h"

using namespace std;

int main(){
    NumComplex z1(3, 11);
    cout<<"Z1 na forma polar-> "<<z1.toStringPol()<<endl;
    cout<<"Z1 na forma retangular-> "<<z1.toStringRet()<<endl;

    NumComplex z2(20,0);
    cout<<"Z2 na forma retangular-> "<<z2.toStringRet()<<endl;

    NumComplex z3(0,0);

    z3 = z1+z2;
    cout<<"Z3 = z1+z2 na forma retangular-> "<<z3.toStringRet()<<endl;
    return 0;
}

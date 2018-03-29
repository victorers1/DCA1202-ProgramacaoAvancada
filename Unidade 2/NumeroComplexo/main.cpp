#include <iostream>
#include "numcomplex.h"

using namespace std;

int main(){
    NumComplex z1(3.0, 5.0);
    cout<<"Z1 na forma polar-> "<<z1.toStringPol()<<endl;
    cout<<"Z1 na forma retangular-> "<<z1.toStringRet()<<endl;

    NumComplex z2(20.0,0.0);
    cout<<"Z2 na forma retangular-> "<<z2.toStringRet()<<endl;

    NumComplex z3(0.0,0.0);
    z3 = z1+z2;
    cout<<"Z3 = z1+z2 na forma retangular-> "<<z3.toStringRet()<<endl;

    NumComplex z4(0.0, 4.0);
    z4 = z1*z2;
    cout<<"z4 = z1*z2: "<<z4.toStringRet()<<endl;

    NumComplex z5(-2.0, 0.0);
    cout<<"z5: "<<z5.toStringRet()<<endl;
    cout<<"Fase de z5: "<<z5.fase()<<endl;

    z3 = z5^1;
    cout<<"z3 = z5^1 = "<<z3.toStringRet()<<endl;

    z3 = z5^3;
    cout<<"z3 = z5^3 = "<<z3.toStringRet()<<endl;

    z2 = z1^3;
    cout<<"z2 = z1^3 = "<<z2.toStringRet()<<endl;

    z2>z1? cout<<"z2>z1" : cout<<"z2<z1"; cout<<endl;

    z1 = NumComplex(9,0);
    z2 = NumComplex(0,8);
    z2>z1? cout<<"z2>z1" : cout<<"z2<z1"; cout<<endl;

    cout<<endl;



    return 0;
}

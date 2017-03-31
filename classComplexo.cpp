#include <iostream>
#include <cmath>
using namespace std;

class Complexo{
    private:
        float re,im;

    public:
        Complexo(){
            re=0; im=0;
        }
        Complexo(float r, float i){
            re = r; im = i;
        }

        float norm(float r, float i){
            return sqrt(r*r + i*i);
        }

        int quad(float r, float i){
            int q=0;
            if(r>0){
                if(i>0) q=1;
                else q=4;
            } else{
                if(i>0) q=2;
                else q=3;
            }
            return q;
        }

        void setRe(float r){re = r;}
        void setIm(float i){im = i;}
        float getRe(){return re;}
        float getIm(){return im;}

        void toString(){
           cout<<endl<<re<< " + " <<im<< " *j\n";
        }
};

Complexo soma(Complexo c1, Complexo c2){
    Complexo c3(c1.getRe() + c2.getRe(), c1.getIm() + c2.getIm());
    return c3;
}

Complexo subt(Complexo c1, Complexo c2){
    Complexo c3(c1.getRe() - c2.getRe(), c1.getIm() - c2.getIm());
    return c3;
}

Complexo mult(Complexo c1, Complexo c2){
    Complexo c3;
    c3.setRe(c1.getRe()*c2.getRe() - c1.getIm()*c2.getIm());
    c3.setIm(c1.getRe()*c2.getIm() + c2.getRe()*c1.getIm());
    return c3;
}

Complexo div(Complexo c1, Complexo c2){
    Complexo c3;
    float divisor = pow(c2.getRe(),2) + pow(c2.getIm(),2);
    c3.setRe((c1.getRe()*c2.getRe()+c1.getIm()*c2.getIm())/divisor);
    c3.setIm((c2.getRe()*c1.getIm() - c1.getRe()*c2.getIm())/divisor);
    return c3;
}

Complexo pot(Complexo c, int exp){
    Complexo x = c;
    for(int i=0; i<exp-1; i++){
        x = mult(x,c);
    }
    return x;
}


int main(void){
    Complexo c(4.5, 1.2);
    c.toString();

    c.setRe(1.2);
    c.setIm(4.5);
    c.toString();

    c = pot(c,4);
    c.toString();
    return 0;
}

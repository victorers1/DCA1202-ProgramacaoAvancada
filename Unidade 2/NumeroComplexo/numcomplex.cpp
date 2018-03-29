#include "numcomplex.h"

string NumComplex::toStringRet(){
    stringstream saida;
    saida << fixed << setprecision(3) << real << " + j" << imag;
    return saida.str();

}

string NumComplex::toStringPol(){

    stringstream saida;
    saida << fixed << setprecision(3) << "Modulo: "<< modulo() << ", Fase: " << fase();
    return saida.str();
}

float NumComplex::modulo(){
    return sqrt(real*real + imag*imag);
}

float NumComplex::fase(){
    if(real==0){
        if(imag>=0) return PI/2.0;//atan(INFINITY);
        else return 3.0*PI/2.0;//atan(-INFINITY);
    } else if(imag==0){
        if(real>=0) return 0;
        else return -PI;
    } else
        return atan(imag/real);
}

void NumComplex::convert(float modulo, float fase){
    setReal(modulo*cos(fase));
    setImag(modulo*sin(fase));
}

void NumComplex::operator=(NumComplex c){
    this->real = c.real;
    this->imag = c.imag;
}

NumComplex NumComplex::operator+(NumComplex c){
    NumComplex *n = new NumComplex(0,0);

    n->setReal(this->real + c.getReal());
    n->setImag(this->imag + c.getImag());
    return *n;
}
NumComplex NumComplex::operator-(NumComplex c){
    NumComplex *n = new NumComplex(0,0);

    n->setReal(this->real - c.getReal());
    n->setImag(this->imag - c.getImag());
    return *n;
}
NumComplex NumComplex::operator/(NumComplex c){
    NumComplex *n = new NumComplex(0,0);
    float m = this->modulo() / c.modulo();
    float f = this->fase() - c.fase();
    n->convert(m,f);

    return *n;
}
NumComplex NumComplex::operator*(NumComplex c){
    NumComplex *n = new NumComplex(0,0);
    float m = this->modulo() * c.modulo();
    float f = this->fase() + c.fase();
    n->convert(m,f);

    return *n;
}
NumComplex NumComplex::operator^(int d){
    if(this->real==0 && this->imag==0){
        if(d==0)
            throw 2; //operação inválida
        else
            return NumComplex(0,0);

    }else{
        if(d==0)
            return NumComplex(1,0);
        else{
            NumComplex n(1,0); //elemento neutro da multiplicação: 1+j0
            for(int i=1; i<=d; i++){
                n = n*(*this);
            }

            return n;
        }
    }
}
bool NumComplex::operator>(NumComplex c){
    if(this->modulo() > c.modulo())
        return  true;
    else
        return false;
}
bool NumComplex::operator<(NumComplex c){
    if(this->modulo() < c.modulo())
        return true;
    else
        return false;
}



NumComplex::NumComplex(float real, float imag){
    this->real = real;
    this->imag = imag;
}
NumComplex::NumComplex(float real){
    this->real = real;
    this->imag = 0;
}
NumComplex::NumComplex(){
    this->real = 0;
    this->imag = 0;
}

float NumComplex::getReal() const{
    return real;
}
void NumComplex::setReal(float value){
    try{
        real = value;
    }catch(exception& e){
        cerr<<"Erro: "<<e.what();
    }

}
float NumComplex::getImag() const{
    return imag;
}
void NumComplex::setImag(float value){
    try{
        imag = value;
    }catch(exception& e){
        cerr<<"Erro: "<<e.what();
    }
}

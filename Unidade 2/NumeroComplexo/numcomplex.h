#ifndef NUMCOMPLEX_H
#define NUMCOMPLEX_H

#include <iostream>
#include <sstream>
#include <math.h>
#include <exception>
#include <cctype>
#include <iomanip>
#define PI 3.14159265359
using namespace std;

class NumComplex{
private:
    float real, imag;
public:
    NumComplex(float real, float imag);
    NumComplex(float real);
    NumComplex();

    float getReal() const;
    void setReal(float value);
    float getImag() const;
    void setImag(float value);

    string toStringRet();
    string toStringPol();
    float modulo();
    float fase();
    void convert(float modulo, float fase);

    void operator=(NumComplex c);
    NumComplex operator+(NumComplex c);
    NumComplex operator-(NumComplex c);
    NumComplex operator/(NumComplex c);
    NumComplex operator*(NumComplex c);
    NumComplex operator^(int d);

    bool operator>(NumComplex c);
    bool operator<(NumComplex c);

};

#endif // NUMCOMPLEX_H

#include <iostream>
#include <cmath>
#include "point.h"


using namespace std;

Point::Point(){
    //cout<<"Ponto criado\n";
}

Point::~Point(){
    //cout<<"Ponto destruido\n";
}
Point::Point(float a, float b){
    x=a; y=b;
}

void Point::setX(float mx){
    x = mx;
}

void Point::setY(float my){
    y = my;
}

void Point::setXY(float mx, float my){
    x = mx; y = my;
}

float Point::getX(){
    return x;
}

float Point::getY(){
    return y;
}

void Point::add(Point p1){
    x += p1.x; //só é possível acessar atributos de p1 porque esta é uma função da classe a qual p1 pertence
    y +=  p1.y;
}

void Point::sub(Point p1){
    x -= p1.x;
    y -= p1.y;

}

float Point::norma(){
    return (sqrt(x*x + y*y));
}

void Point::translada(float a, float b){
    x+=a; y+=b;
}

void Point::imprime(){
    cout<<"("<< x <<", "<< y <<")";
}

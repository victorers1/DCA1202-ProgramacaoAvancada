#ifndef POINT_H
#define POINT_H

class Point{
private:
    float x;
    float y;
public:
    Point();
    ~Point();
    Point(float a, float b);
    Point(Point &copia);
    void setX(float mx); //define ovalor da coordenada X
    void setY(float my); //define o valor da coordenada Y
    void setXY(float mx, float my); //define, em uma mesma função, valor de X e Y
    float getX(); //recupera o valore de X
    float getY(); //recupera o valor de Y
    void add(Point p1); //soma as coordendas deste ponto com as de outro fornecido no argumento
    void sub(Point p1); //subtrai as coordendas deste ponto com outro
    float norma(); //calcula distância com a origem
    void translada(float a, float b); //move o ponto para o X += a e Y += b
    void imprime(); //imprime o ponto na forma (X,Y)

};

#endif // POINT_H

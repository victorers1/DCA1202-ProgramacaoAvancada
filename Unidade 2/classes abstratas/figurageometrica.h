#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H


class FiguraGeometrica{ //é uma classe abstrata
public:
    FiguraGeometrica();
    virtual void draw()=0; //função virtual pura: as classes herdeiras são obrigadas a implementar a função draw();
};

#endif // FIGURAGEOMETRICA_H

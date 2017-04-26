#ifndef RETANGULO_H
#define RETANGULO_H
#include "poligono.h"

/**
 * @brief A classe Retangulo modela o subgrupo dos polígonos que classificam-se como retângulos
 *
 * A classe modela polígonos com exatos 4 vértices e todos os ângulos internos iguais a 90º graus
 */
class Retangulo: public Poligono {
public:
    /**
     * @brief Retangulo construtor padrão da classe
     *
     * O construtor padrão aloca um vetor de 4 Point dinamicamente na memória
     */
    Retangulo();
    /**
     * @brief ~Retagulo destrutor padrão da classe
     *
     * O destrutor padrão libera da memória o vetor de 4 Point alocado
     */
    ~Retangulo();
    /**
     * @brief Retangulo declara todos os pontos do retângulo baseado no vértice superior esquerdo e as dimensões nos eixos
     * @param x coordenada x do vértice superior esquerdo
     * @param y coordenada y do vértice superior esquerdo
     * @param largura dimensão horizontal do retângulo declarado
     * @param altura dimensão vertical do retângulo declarado
     */
    Retangulo(float x, float y, float largura, float altura);
private:
    /**
     * @brief l largura do retângulo
     */
    /**
     * @brief h altura do retângulo
     */
    float l, h; //largura e altura
};

#endif // RETANGULO_H

#ifndef POLIGONO_H
#define POLIGONO_H
#include "point.h"

/**
 * @brief A classe Poligono modela um polígono de até 100 vértices contido no plano cartesiano
 */
class Poligono{
public:
    /**
     * @brief Poligono construtor padrão da classe
     *
     * No construtor é feita a alocação dinâmica do vetor de 100 objetos da classe Point
     */
    Poligono();
    /**
     * @brief ~Poligono construtor padrão da classe
     *
     * No destrutor é feita a liberação da memória alocada para os 100 Point
     */
    ~Poligono();
    /**
     * @brief addVertice guarda valores das coordenadas do ponto p1 no elemento do vetor de Point cujo índice é o número de vértices atual do polígono
     * @param p1 ponto a ser adicionado no polígono
     */
    void addVertice(Point p1);//insere novo ponto no polígono, assumindo que eles são inseridos em sentido anti-horário
    /**
     * @brief addVertice guarda valores das coordenadas do ponto p1 no elemento do vetor de Point cujo índice é o número de vertices atual do polígono
     * @param mx valor x da coordenada
     * @param my valor y da coordenada
     */
    void addVertice(float mx, float my);
    /**
     * @brief getNumVertice recupera valor da quantidade de vértices
     * @return número atual de vértices do polígono
     */
    int getNumVertice(); // retorna o número de pontos do polígono
    /**
     * @brief area calcula a área do polígono desde que seus pontos estejam ordenados no vetor de Point em sentido anti-horário
     * @return área do polígono
     */
    float area(); //Calcula a área.
    /**
     * @brief translada move cada vértice para a posição (x+a y+b)
     * @param a valor a ser adicionado ao x
     * @param b valor a ser adicionado ao y
     */
    void translada(float a, float b); //move cada vértice do polígono para o ponto (x+a,y+b)
    /**
     * @brief rotaciona calcula as coordendas de cada ponto após a rotação em um dado ângulo e em relação ao eixo de centro especificado
     * @param eixo eixo de centro de rotação
     * @param ang ângulo em graus
     */
    void rotaciona(Point eixo, float ang); //rotaciona o polígono em "ang" graus em torno do ponto p1
    /**
     * @brief rotaciona  rotaciona cada ponto do polígono em dado ângulo e em relação a um eixo de centro
     * @param xc coordenada x do centro de rotação
     * @param yc coordenada y do centro de rotação
     * @param ang ângulo em graus
     */
    void rotaciona(float xc, float yc, float ang);
    /**
     * @brief imprime exibe na saída padrão do programa os pontos que formam o polígono
     */
    void imprime();
    /**
     * @brief centroide realiza o cálculo do ponto denominado o centro geométrico do polígono
     * @return ponto que representa o centro geométrico do polígono
     */
    Point centroide();

protected: //protected significa que as subclasses podem acessá-los como se fossem seus atributos
    /**
     * @brief p ponteiro para um objeto da classe Point
     */
    Point *p;
    /**
     * @brief nVert número de vértices do polígono
     */
    int nVert=0; // número de vértices, 0 <= nVert <= 100
};



#endif // POLIGONO_H

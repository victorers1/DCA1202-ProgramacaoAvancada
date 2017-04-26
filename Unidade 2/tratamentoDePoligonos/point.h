#ifndef POINT_H
#define POINT_H
/**
 * @brief A classe Point modela um ponto contido no plano cartesiano bidimensional
 */
class Point{
private:
    /**
     * @brief x primeiro elemento do par ordenado
     * @brief y segundo elemento do par ordenado
     */
    float x;
    float y;
public:
    /**
     * @brief Point construtor padrão da classe
     */
    Point();
    /**
     * @brief ~Point destrutor padrão da classe
     */
    ~Point();
    /**
     * @brief Point construtor com inicialização do par ordenado
     * @param a valor de x
     * @param b valor de y
     */
    Point(float a, float b);
    /**
     * @brief setX sobrescreve valor da coordenada x com o valor passado no argumento
     * @param mx novo valor de x
     */
    void setX(float mx); //define ovalor da coordenada X
    /**
     * @brief setY sobrescreve valor da coordenada y com o valor passado no argumento
     * @param my novo valor de y
     */
    void setY(float my); //define o valor da coordenada Y
    /**
     * @brief setXY sobrescreve simultaneamente valores de x e y do par ordenado
     * @param mx novo valor de x
     * @param my novo valor de y
     */
    void setXY(float mx, float my); //define, em uma mesma função, valor de X e Y
    /**
     * @brief getX recupera valor de x
     * @return valor atual da coordenada x
     */
    float getX(); //recupera o valor de X
    /**
     * @brief getY recupera valor de y
     * @return valor atual da coordenada y
     */
    float getY(); //recupera o valor de Y
    /**
     * @brief add soma as coordenadas do ponto com as de outro objeto da classe Point passado como argumento
     * @param p1 objeto da classe Point
     */
    void add(Point p1); //soma as coordendas deste ponto com as de outro fornecido no argumento
    /**
     * @brief sub sutrai as coordendas do ponto com as de outro objeto da classe Point passado como argumento
     * @param p1 objeto da classe Point
     */
    void sub(Point p1); //subtrai as coordendas deste ponto com outro
    /**
     * @brief norma calcula norma euclidiana do ponto, sua distância a origem do sistema de coordenadas
     * @return norma do ponto
     */
    float norma(); //calcula distância com a origem
    /**
     * @brief translada move um ponto (x,y) para o ponto de coordenadas (x+a, y+b)
     * @param a valor a ser adicionado ao x
     * @param b valor a ser adicionado ao y
     */
    void translada(float a, float b); //move o ponto para o X += a e Y += b
    /**
     * @brief imprime mostra o ponto na saída padrão do programa com a notação: (X,Y)
     */
    void imprime(); //imprime o ponto na forma (X,Y)
};

#endif // POINT_H

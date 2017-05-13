#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <fstream>

using namespace std;

class Screen{
private:
  // armazenam o tamanho da tela de desenho
  // no de linhas e de colunas
  int nlin, ncol;

  // guarda o caractere usado para desenhar
  char brush;

  // armazena a matriz da tela
  vector< vector<char> > mat;
public:
  // construtor da classe
  Screen();

  //dimensiona a matriz de caracteres
  void dim(int x, int y);

  int getLin(); //recupera número de linhas
  int getCol(); //recupera número de colunas

  // desenha um pixel da matriz usando o caratere
  // guardado em 'brush'
  void setPixel(int x, int y);

  // limpa a tela
  void clear();

  // muda o caractere de desenho
  void setBrush(char brush);

  // envia a tela para um stream de saida
  friend ostream &operator<<(ostream &os, Screen &t);
};


#endif // SCREEN_H

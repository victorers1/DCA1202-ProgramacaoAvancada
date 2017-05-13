#include <iostream>
#include <fstream>

#include "figurageometrica.h"
#include "circulo.h"
#include "reta.h"
#include "retangulo.h"


using namespace std;

int main(void){
    ifstream entra;
    ofstream saida;
    Screen tela(50,50);
    tela.setBrush('a');

    Retangulo r(1,1, 30,40);
    r.draw(tela);

    entra.open("comandos.txt");
    saida.open("C:/Users/Suporte/Downloads/DCA1202-programacaoAvancada-master/Unidade 2/tratamentoDeClassesAbstratas/tratamento_abstrato/desenho.txt");

    saida<<tela;

    saida.close();
    entra.close();
    return 0;
}

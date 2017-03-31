#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* realoca(int *x, int antigo, int novo){
    int *y;
    y = (int*) malloc(novo*sizeof(int));
    if(y == NULL || novo==antigo){
        exit(0);
    }

    printf("novo: %d, antigo: %d\n", novo, antigo);
    if(novo>antigo){
        int i=0;
        memcpy(y,x, antigo*sizeof(int));
        for(i=antigo; i<novo; i++){ //preenche o excesso com zeros
            y[i] = 0;
        }
    } else { //antigo>novo
        memcpy(y,x, novo*sizeof(int));
    }
    free(x);//libera o espaço de memória dado no primeiro argumento

    return y;
}

void realoc(int **x, int antigo, int novo){
    int *y;
    y = (int*) malloc(novo*sizeof(int));
    if(y==NULL || novo ==antigo){
        exit(0);
    }
    printf("novo: %d, antigo: %d\n", novo, antigo);
    if(novo>antigo){
        memcpy(y, *x, antigo*sizeof(int));
        int i=0;
        for(i=antigo; i<novo; i++){ y[i] = 0; }
    } else {//antigo>novo
        memcpy(y, *x, novo*sizeof(int));
    }

    /*se é declarado um
     * int *x, a;
     *e é executado um
     * x = &a;
     *a expressão
     * x retorna o endereço de a
     * *x retorna o conteúdo do endereço guardado por x, valor de a
     *
    */
    free(*x); //*x é equivalente a *aux, ou seja, conteúdo do endereço guardado por 'aux', que é o próprio 'a' (ou 'b');
    *x = y; //aqui muda o conteúdo do endereço guardado por aux, que é o endereço 'a'. Assim, estamos mudando o endereço 'a' sem retornar nada.

}

void print(int *x, int tam){
    int i=0;
    for(i=0; i<tam; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}

int main(){
    //REALOCA INT*
    int *x, *y, *z;
    x = (int*) malloc(10*sizeof(int)); //vetor de 10 ints
    y = (int*) malloc(5*sizeof(int)); //vetor de 5 ints
    z = (int*) malloc(15*sizeof(int)); //vetor de 15 ints
    int i=0;

    for(i=0; i<10; i++){ x[i] = i; } //preenche x
    printf("vetor x:\n"); print(x, 10);

    y = realoca(x, 10, 5);//diminui de 10 p/ 5
    printf("vetor y:\n");
    print(y, 5);
    //Como o espaço de memória x foi liberado na última chamada de realoca(), não podemos mais executar realoca(x,..,..);
    z = realoca(y, 5, 10);//aumenta de 5 p/ 10
    //Agora o espaço de memória apontado por 'y' foi apagado.
    printf("vetor z:\n");
    print(z, 10);
    //REALOCA INT*
    printf("\n\n");


    //REALOCA VOID
    int *a, *b;
    a = (int*) malloc(10*sizeof(int)); //vetor de 10 ints
    b = (int*) malloc(5*sizeof(int)); //vetor de 5 ints

    for(i=0; i<10; i++){ a[i] = i; } //preenche a (10 inteiros)
    for(i=0; i<5; i++){b[i] = i; } //prenche b (5 inteiros)
    printf("vetor a:\n"); print(a, 10);

    int **aux; //aux é um ponteiro p/ int que guarda o endereço de outro ponteiro
    aux = &a; //aux aponta para 'a' que, por sua vez, aponta para um endereço de memória de 10*sizeof(int) Bytes
    realoc(aux, 10, 5); //diminui tamanho de 'a' p/ 5
    printf("vetor a:\n");print(a, 5);

    aux = &b; //aux recebe endereço de b
    realoc(aux, 5, 10); //aumenta o tamanho de b p/ 10;
    printf("vetor b:\n"); print(b, 10);

    //REALOCA VOID
    return 0;
}

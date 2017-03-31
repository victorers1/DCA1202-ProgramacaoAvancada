#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int **A, int lin, int col){
    int i,j;
    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            printf("%3d ", A[i][j]);
        }printf("\n");
    }

}

void transposta(int **src, int **dest, int lin, int col){
    int i,j;
    for(i=0; i<col; i++){
        for(j=0; j<lin; j++){
            dest[i][j] = src[j][i];
        }
    }
}

int main(void){
    int **A, **B, lin=3, col=4;
    int i,j;

    srand(time(NULL));

    /*ALOCAÇÃO DE MEMÓRIA - ineficiente
    A = (int**) malloc(lin*sizeof(int*)); // cria vetor de int*
    B = (int**) malloc(col*sizeof(int*)); //cria vetor de int*

    for(i=0; i<lin; i++){
        A[i] = (int*) malloc(col*sizeof(int));//cria vetor de int e guarda endereço em A[i]
    }
    for(i=0; i<col; i++){
        B[i] = (int*) malloc(lin*sizeof(int));
    }*/

    //ALOCAÇÃO DE MEMÓRIA - eficiente
    A = (int**) malloc(lin*sizeof(int*)); // cria vetor de int*
    B = (int**) malloc(col*sizeof(int*)); //cria vetor de int*

    A[0] = (int*) malloc(lin*col*sizeof(int)); //só executa dois malloc()
    B[0] = (int*) malloc(col*lin*sizeof(int));

    for(i=1; i<lin; i++){
        A[i] = A[i-1] + col;
    }
    for(i=1; i<col; i++){
        B[i] = B[i-1] + lin;
    }

    //PREENCHENDO A
    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            A[i][j] = rand() % 100;
            B[j][i] = 0;
        }
    }

    //CÁLCULO DA TRANSPOSTA
    printf("Matriz A:\n");
    print(A, lin, col);
    transposta(A,B, lin, col);
    printf("\nMatriz B:\n");
    print(B, col, lin);

    //LIBERAÇÃO DA MEMÓRIA
    for(i=0; i<lin; i++){
        free(A[i]);
    }
    for(j=0; j<col; j++){
        free(B[j]);
    }
    free(A);
    free(B);
    return 0;
}

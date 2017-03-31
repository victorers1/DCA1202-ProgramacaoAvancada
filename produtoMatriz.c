#include <stdio.h>
#include <stdlib.h>

void produtoMatriz(int **A, int **B, int **C, int linA, int colA, int colB){
    int i,j,k, soma=0;
    for(i=0; i<linA; i++){
        for(j=0; j<colB; j++){
            soma=0;
            for(k=0; k<colA; k++){
                soma+= A[i][k]*B[k][j];
            }
            C[i][j] = soma;
        }
    }
}

void print(int **A, int lin, int col){
    int i,j;
    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            printf("%2d ", A[i][j]);
        } printf("\n");
    }
}

int main(){
    int **A, **B, **C;
    int linA=9, colA=9;
    int linB = colA, colB = 10;

    A = (int**) malloc(linA*sizeof(int*));
    B = (int**) malloc(linB*sizeof(int*));
    C = (int**) malloc(linA*sizeof(int*));
    A[0] = malloc(linA*colA*sizeof(int));
    B[0] = malloc(linB*colB*sizeof(int));
    C[0] = malloc(linA*colB*sizeof(int));


    int i,j;
    for(i=1; i<linA; i++){
        A[i] = A[i-1] + colA;
    }

    for(i=1; i<linB; i++){
        B[i] = B[i-1] + colB;
    }

    for(i=1; i<linA; i++){
        C[i] = C[i-1] + colB;
    }

    //preenchimento
    for(i=0;i<linA; i++) for(j=0; j<colA; j++) A[i][j] = i+j;
    for(i=0;i<linB; i++) for(j=0; j<colB; j++) B[i][j] = i*j;
    for(i=0;i<linA; i++) for(j=0; j<colB; j++) C[i][j] = 0;


    printf("\nMatriz A:\n");
    print(A, linA, colA);

    printf("\nMatriz B:\n");
    print(B, linB, colB);
    produtoMatriz(A, B, C, linA, colA, colB);

    printf("\nMatriz C:\n");
    print(C, linA, colB);

    for(i=0; i<linA; i++){
        free(A[i]);
    }
    for(i=0; i<linB; i++){
        free(B[i]);
    }
    for(i=0; i<linA; i++){
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);


    return 0;
}



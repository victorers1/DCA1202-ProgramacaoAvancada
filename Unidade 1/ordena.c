#include <stdio.h> //printf(), scanf()
#include <stdlib.h> // malloc(), free(), rand()

//aplica o bubble sort
void ordena(void *base, int tam, int tamTipo, int (*ptr_compara)(const void *a, const void *b) , void (*ptr_troca)(const void *a,const void *b)){
    int i,j;

    for(i=0; i<tam-1; i++){
        for(j=1; j<tam; j++){
            if((*ptr_compara)(&base + j*tamTipo-1, &base + j*tamTipo) > 0){ //se a > b, executa a troca
                (*ptr_troca)(&base + j*tamTipo, &base + j*tamTipo-1);
            }
        }
    }

}

/*
 * Funções de comparação retornam:
 * valor negativo, se a < b
 * 0 , se a == b
 * valor positivo, se a > b
*/
int comparaInt(const void *a, const void *b){
    printf("comparando %d com %d\n", *(int*)a, *(int*)b);
    return (*(int*)a - *(int*)b);
}
int comparaFlo(const void *a, const void *b){
    return (*(float*)a - *(float*)b);
}

void trocaInt(const void *a,const void *b){
    int z;
    printf("trocando %d com %d\n", *(int*)a, *(int*)b);
    z = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = z;
}
void trocaFlo(const void *a,const void *b){
    float z;
    z = *(float*)a;
    *(float*)a = *(float*)b;
    *(float*)b = z;
}


void printInt(const void *a, int t){
    int i=0;
    int *x = (int*)a;
    for(i=0; i<t; i++){
        printf("%3d ", x[i]);
    }
}
void printFlo(const void *a, int t){
    int i=0;
    float *x = (float*)a;
    for(i=0; i<t; i++){
        printf("%4.1f ", x[i]);
    }
}


int main(){
    //printf("YO");
    int t=0, tamTipo=0, tx=3, ty=5; //tamanhos de x e y
    void *base; //ponteiro que aponta p/ o vetor que será comparado. Pode ser 'int' ou 'float'
    int *x;
    float *y;

    int (*ptr_compara)(const void *a, const void *b);//ponteiro p/ função de comparação
    void (*ptr_troca)(const void *a, const void *b); //ponteiero p/ função de trocar valores
    void (*ptr_print)(const void *a, int t); // ponteiro p/ função de imprimir vetor de 'int' ou 'float'

    //criação dos vetores
    x = (int*) malloc(tx*sizeof(int));
    y = (float*) malloc(ty*sizeof(float));
    //preenchimento dos vetores
    int i;
    for(i=0; i<tx; i++) x[i] = rand()%100;
    for(i=0; i<ty; i++) y[i] = (rand()%100)/(float)10;

    printf("Voce tem dois vetores:\nUm de valores inteiros ->");
    for(i=0; i<tx; i++){
        printf("%3d ", x[i]);
    }

    printf("\nE esse outro de valores reais ->");
    for(i=0; i<ty; i++){
        printf("%4.1f ", y[i]);
    }

    int op; //recebe a escolha o usuário
    printf("\nEscolha qual vetor sera ordenado:\n1-Inteiro\n2-Real\n");
    scanf("%d", &op);
    //atribução dos ponteiros p/ função
    if(op==1){
        ptr_compara = comparaInt;
        ptr_troca = trocaInt;
        base = (int*)x; //vetor 'base' é atualizado como um vetor p/ inteiro cujo endereço é o valor de 'x'
        ptr_print = printInt;
        t=tx; //tamanho do vetor a ser ordenado
        tamTipo = sizeof(int);

    } else{ //o mesmo procedimento de cima é feito abaixo
        ptr_compara = comparaFlo;
        ptr_troca = trocaFlo;
        base = (float*)y;
        ptr_print = printFlo;
        t=ty;
        tamTipo = sizeof(float);
    }

    printf("\nAntes de ordenar: ");
    (*ptr_print)(base, t); //imprime o vetor de tipo escolhido pelo usuário
    ordena(base, t, tamTipo, ptr_compara, ptr_troca); //ordena o vetor
    printf("\n\nDepois de ordenar: ");
    (*ptr_print)(base, t); //imprime após a ordenação

    printf("\ngg ez\n\n");
    free(x);
    free(y);
    free(ptr_compara);
    free(ptr_troca);
    free(ptr_print);
    return 0;
}

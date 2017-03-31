#include <stdio.h> //printf(), scanf()
#include <stdlib.h> //malloc(), free(), qsort()

/*
 * Função compara retorna:
 * valor negativo, se a < b
 * 0,  se a == b
 * valor positivo, se a > b
*/
int compara(const void* a, const void* b){
    return (*(float*)a - *(float*)b); //subtração sendo usada para verificar qual dos argumentos é maior
}

//imprime na tela o vetor 'v' de tamaho 't' formatado
void print(float *v, int t){
    int i=0;
    for(i=0; i<t; i++){ //percorre vetor passado como argumento
        /* imprime valores contidos em v[i] formatados com 2
         * casas decimais e ocupando 5 espaços ao todo
         */
        printf("%5.2f ", v[i]);
    }
}

int main(){
    float *val; //ponteiro de aponterá p/ vetor de float
    int i, n=5; //n=número de valores

    val = (float*) malloc(n*sizeof(float)); //alocação de n*(tamanho da variável float) Bytes
    for(i=0; i<n; i++){ //leitura dos n valores
        scanf("%f", &val[i]);
    }
    printf("Antes do qsort:\n");
    print(val, n); printf("\n");

    //declaração do ponteiro para função
    //seria mais útil caso houvesse outros vetores de outros tipos primitivos
    float (*ptr_comp)(const void *a, const void *b);
    ptr_comp = compara;

    //chamada do qsort(vetor base, tamanho da base, tamanho de cada elemento, função p/ comparar elementos)
    qsort(val, n,sizeof(float), ptr_comp);

    printf("\nDepois do qsort:\n");
    print(val, n); printf("\n");

    //liberação da memória
    free(val);
    free(ptr_comp);
    return 0;
}

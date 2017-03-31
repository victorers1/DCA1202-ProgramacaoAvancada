#include <stdio.h>
#include <math.h>

double raizQ (double n, float (*func)(double)){
    return (*func)(n);
}

int main (void){
    double n= 22.0; //valor double
    double (*p)(double); //ponteiro p/ função de recebe double e retorna double

    p=sqrt;

    n = raizQ (n, p);

    printf("%f\n", n);
    return 0;
}


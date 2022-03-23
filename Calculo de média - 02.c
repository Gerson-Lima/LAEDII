#include <stdio.h>
# include <stdlib.h>
# include <time.h>

float * gerador ( size_t n, int seed ) {
    srand ( seed );
    float * res = malloc ( n * sizeof ( int ));
    for ( size_t i = 0; i < n ; i ++) {
        res [ i ] = rand () % 1000;
    }
    return res ;
}

float Media_Iterativa(float V[], int n){
    float soma = 0;
    for (size_t i = 0; i < n; i++){
    
        soma += V[i];
    }
    return soma / n;
}

float Media_Recursiva(float V[], int n){
    if(n == 1){
        return V[0];
    } else{
        return (V[n-1] + (n-1)* Media_Recursiva(V, n-1)) / n;
    }
}

int main () { 
    size_t n = 100;

    float * aleatorio = gerador (n, time(NULL));
    float resRecursiva = Media_Recursiva(aleatorio, n);
    float resIterativa = Media_Iterativa(aleatorio, n);

    printf("A média Recursiva é %f\n", resRecursiva);
    printf("A média Iterativa é %f\n", resIterativa);
}
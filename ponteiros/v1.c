#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define MX 10

int main(){
    char x[TAM];
    int v[TAM];

    srand(time(NULL));
    //preencher o vetor
    for (int k=0; k<TAM; k++){
        *(x+k) = rand() % MX;
        *(v+k) = rand() % MX;
    }

    //imprimir o primeiro vetor
    for (int k=0; k<TAM; k++){
        printf("[%p] %d\n",x+k,*(x+k));
    }

    puts("======");
    //imprimir o segundo vetor
    for (int k=0; k<TAM; k++){
        printf("[%p] %d\n",v+k,*(v+k));
    }

    return 0;
}
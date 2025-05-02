#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define TAM 100000
#define TAM 50
#define MX 10


int main(){

    int vetor[TAM] = {0};
    int freq[MX] = {0};

    // Popular o vetor
    srand(time(NULL));
    for (int k=0; k<TAM; k++){
        vetor[k] = rand() % MX;
    }
    
    // Imprimir Vetor 
    for (int k=0; k<TAM; k++){
        printf("%d ",vetor[k]);
    }
    printf("\n");

    // Contar frequência de elementos no vetor
    for (int k=0; k<TAM; k++){
        freq[vetor[k]]++;
    }

    // Imprimir Frequência
    for (int k=0; k<MX; k++){
        printf("%d ",freq[k]);
    }
    printf("\n");

    // Somatório do vetor de frequência
    int s = 0;
    for (int k=0; k<MX; k++){
        s += freq[k];
    }

    float freqnorm[MX];
    for (int k=0; k<MX; k++){
        freqnorm[k] = ((float) freq[k]) / s;
    }

    // Imprimir Frequência no intervalo 0-1.
    for (int k=0; k<MX; k++){
        printf("%.2f ",freqnorm[k]);
    }
    printf("\n");

    float sn = 0.0;
    for (int k=0; k<MX; k++){
        sn += freqnorm[k];
    }

    printf("Somatório do vetor de freqnorm: %.2f\n",sn);

    return 0;

}
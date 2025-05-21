#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define MX 100

void preencherVetor(unsigned int *);
void imprimirVetor(unsigned int *);
void imprimirPares(unsigned int *);

int main(){
    unsigned int vetor[TAM]; 

    srand(time(NULL));

    preencherVetor(vetor);
    
    puts("===");
    puts("Vetor Gerado");
    imprimirVetor(vetor);

    puts("===");
    puts("Elementos Pares do Vetor: ");
    imprimirPares(vetor);
    puts("===");

    return 0;
}

void preencherVetor(unsigned int *p){
    for (int k=0; k<TAM; k++){
        *(p+k) = rand() % MX;
    }
}

void imprimirVetor(unsigned int *p){
    for (int k=0; k<TAM; k++){
        printf("[%p] %u\n",p+k,*(p+k));
    }
}

void imprimirPares(unsigned int *p){
    for (int k=0; k<TAM; k++){
        if (!(*(p+k)%2)) printf("%u ",*(p+k));
    }
}
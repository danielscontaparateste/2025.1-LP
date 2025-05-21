#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define MX 100

#define FALSE 0
#define TRUE 1

void preencherVetor(unsigned int *);
void imprimirVetor(unsigned int *);
void buscarValor(unsigned int *, unsigned int);

int main(){
    unsigned int vetor[TAM]; 
    unsigned int x;
    unsigned int *px = &x;

    puts("Digite o valor a ser buscado: ");
    scanf("%u",px);

    // srand(time(NULL));

    preencherVetor(vetor);
    
    puts("===");
    puts("Vetor Gerado");
    imprimirVetor(vetor);

    buscarValor(vetor, x);

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

void buscarValor(unsigned int *pv, unsigned int a){
    char localizado = FALSE; 
    for (int k=0; k<TAM; k++){
        if (a == *(pv+k)){
            printf("Localizado no endereço [%p]\n",pv+k);
            localizado = TRUE;    
            break;
        }
    }
    if (!localizado) printf("%u não existe no vetor\n",a);

}


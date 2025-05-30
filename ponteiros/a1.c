#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 5
#define TAM 3

void preencherVetor(float *, int);
void imprimirVetor(float *, int);
void calcularMedia(float *, int, float *);

int main(){
    float v[TAM];

    srand(time(NULL));
    preencherVetor(v, TAM);
    imprimirVetor(v, TAM);

    float media;
    calcularMedia(v,TAM,&media);
    
    printf("Media: %.2f\n",media);

    // Exemplo de indireção múltipla
    float *pmed1 = NULL;
    pmed1 = &media;

    float **pmed2 = NULL;
    pmed2 = &pmed1;

    puts("======");
    printf("Media (var : media): %.2f\n",media);
    printf("Media (var : pmed1): %.2f\n",*pmed1);
    printf("Media (var : pmed2): %.2f\n",**pmed2);

    return 0;
}

void preencherVetor(float *pv, int t){
    for (int k=0; k<t; k++){
        *(pv + k) = (((float) rand())/RAND_MAX) * (MX-1);
    }
}

void imprimirVetor(float *pv, int t){
    for (int k=0; k<t; k++){
        printf("[%p] %.2f\n",pv+k, *(pv + k));
    }
}

void calcularMedia(float *pv, int t, float *pm){
    float soma = 0;
    for (int k=0; k<t; k++){
        soma += *(pv+k); // soma = soma + *(pv+k);
    }
    *pm = soma / t;
}
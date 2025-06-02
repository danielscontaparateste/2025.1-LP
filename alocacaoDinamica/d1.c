#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 5


void preencherVetor(float *, int);
void imprimirVetor(float *, int);
void calcularMedia(float *, int, float *);
float *getEndMenor(float *, int);
float *getEndMaior(float *, int);
void imprimirValores(float **);

int main(){
    float *v = NULL;
    float *pMenorMaior[2]; // Assunto : Vetor de Ponteiros

    // Alocacao Dinâmica
    int qtd;
    puts("Digite a quantidade de elementos do vetor: ");
    scanf("%d",&qtd);

    v = malloc(qtd * sizeof(float));
    if (v==NULL){
        puts("Memória indisponível");
        exit(1);
    }

    srand(time(NULL));
    // printf("Seed: %ld\n", time(NULL));
    // printf("Primeiro rand(): %d\n", rand());
    puts("Gerando o vetor... ");
    // printf("Primeiro rand(): %f\n", ((float) rand())/RAND_MAX);
    printf("Primeiro rand(): %d\n", rand());
    preencherVetor(v, qtd);
    imprimirVetor(v, qtd);

    pMenorMaior[0] = getEndMenor(v, qtd);
    pMenorMaior[1] = getEndMaior(v, qtd);
    
    puts("====");
    // printf("End. Menor: %p\n",pMenorMaior[0]);
    // printf("End. Menor: %p\n",*pMenorMaior);
    // printf("End. Menor: %p\n",pMenorMaior[1]);
    // printf("End. Maior: %p\n",*(pMenorMaior+1));
    
    imprimirValores(pMenorMaior);

    free(v);

    return 0;
}

void preencherVetor(float *pv, int t){
    for (int k=0; k<t; k++){
        *(pv + k) = (((float) rand())/RAND_MAX) * MX;
    }
}

void imprimirVetor(float *pv, int t){
    for (int k=0; k<t; k++){
        printf("[%p] %.2f\n",pv+k, *(pv + k));
    }
}

float *getEndMenor(float *pv, int t){ // Assunto : Funções que devolvem ponteiros
    float *menor = pv;
    for (int k=0; k<t; k++){
        menor = (*(pv+k) < *menor)?pv+k:menor;
    }
    return menor;
}

float *getEndMaior(float *pv, int t){ // Assunto : Funções que devolvem ponteiros
    float *maior = pv;
    for (int k=0; k<t; k++){
        maior = (*(pv+k) > *maior)?pv+k:maior;
    }
    return maior;
}

void imprimirValores(float **pval){
    printf("End. Menor: %p com o valor: %.2f\n",*pval,**pval);
    printf("End. Maior: %p com o valor: %.2f\n",*(pval+1),**(pval+1));
}
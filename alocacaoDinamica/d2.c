#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 5

void preencherVetor(float *, unsigned t);
void imprimirVetor(float *, unsigned t);
void calcularMedia(float *, unsigned t, float *);
float *getEndMenor(float *, unsigned t);
float *getEndMaior(float *, unsigned t);
void imprimirValores(float **);
float *alocaMemoriaFloat(unsigned);

int main(){
    float *v = NULL;
    float *pMenorMaior[2]; // Assunto : Vetor de Ponteiros

    // Alocacao Dinâmica
    unsigned qtd;
    puts("Digite a quantidade de elementos do vetor: ");
    scanf("%u",&qtd);

    if (!(v = alocaMemoriaFloat(qtd))){
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

void preencherVetor(float *pv, unsigned t){
    for (int k=0; k<t; k++){
        *(pv + k) = (((float) rand())/RAND_MAX) * MX;
    }
}

void imprimirVetor(float *pv, unsigned t){
    for (int k=0; k<t; k++){
        printf("[%p] %.2f\n",pv+k, *(pv + k));
    }
}

float *getEndMenor(float *pv, unsigned t){ // Assunto : Funções que devolvem ponteiros
    float *menor = pv;
    for (int k=0; k<t; k++){
        menor = (*(pv+k) < *menor)?pv+k:menor;
    }
    return menor;
}

float *getEndMaior(float *pv, unsigned t){ // Assunto : Funções que devolvem ponteiros
    float *maior = pv;
    for (int k=0; k<t; k++){
        maior = (*(pv+k) > *maior)?pv+k:maior;
    }
    return maior;
}

void imprimirValores(float **pval){
    printf("End. Menor : %p com o valor: %.2f\n",*pval,**pval);
    printf("End. Maior : %p com o valor: %.2f\n",*(pval+1),**(pval+1));
}

float *alocaMemoriaFloat(unsigned q){
    float *p = (float *) malloc(q * sizeof(float));
    return p;
}


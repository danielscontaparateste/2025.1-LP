#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 6
#define MX 10

int main(){

    int vetor[TAM];

    srand(time(NULL));

    //Preencher o vetor
    for (int k=0; k<TAM; k++){
        // scanf("%d",&vetor[k]);
        vetor[k] = rand() % MX; // [0-9]
    }
    
    puts("Vetor antes da ordenação");
    for (int k=0; k<TAM; k++){
        printf("%d ",vetor[k]);
    }
    
    // ordenação - por seleção
    int aux;
    for (int k=0; k<TAM-1; k++){
        for (int j=k+1; j<TAM; j++){
            if (vetor[k]>vetor[j]){
                aux = vetor[k];
                vetor[k] = vetor[j];
                vetor[j] = aux;
            }
        }
    } 

    printf("\n=====\n");
    puts("Vetor APÓS a ordenação");
    for (int k=0; k<TAM; k++){
        printf("%d ",vetor[k]);
    }
    printf("\n");

    //Mediana
    float mediana = (TAM%2)?vetor[TAM/2]:(float)(vetor[TAM/2]+vetor[TAM/2-1])/2;

    printf("Mediana : %.2f\n",mediana);
    
    return 0;
}
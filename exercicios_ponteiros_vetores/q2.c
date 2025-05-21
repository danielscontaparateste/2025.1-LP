#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define MX 100

int main(){
    unsigned int vetor[TAM]; 

    srand(time(NULL));

    for (int k=0; k<TAM; k++){
        *(vetor+k) = rand() % MX;
    }
    
    puts("====");
    puts("Vetor Gerado");
    for (int k=0; k<TAM; k++){
         printf("[%p] %u\n",vetor+k,*(vetor+k));
    }

    puts("====");
    puts("Elementos Pares do Vetor: ");
    for (int k=0; k<TAM; k++){
        if (!(*(vetor+k)%2)) printf("%u ",*(vetor+k));
    }
    puts("====");

    return 0;
}

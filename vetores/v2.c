#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20
#define MX 3
#define INI 20

int main(){

    float v[TAM];

    srand(time(NULL));

    //Gerar os números 
    for (int k=0; k<TAM; k++){
        v[k] = INI + ((float) rand()/RAND_MAX) * MX;
    }

    // Imprimir o número
    for (int k=0; k<TAM; k++){
        printf("%.2f \n",v[k]);
    }

    // Obter maior e menor elemento
    float maior = v[0], menor = v[0];

    for (int k=1; k<TAM; k++){
        maior = (maior < v[k])?v[k]:maior;
        menor = (menor > v[k])?v[k]:menor;
    }

    printf("Maior: %.2f\nMenor: %.2f\nSoma: %.2f\n\n",maior,menor,maior+menor);

    return 0;

}
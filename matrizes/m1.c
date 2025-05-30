#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIN 2
#define COL 3

#define MX 100

int main(){

    unsigned int mat[LIN][COL];

    //Popular matriz
    srand(time(NULL));
    for(int k=0; k<LIN; k++){
        for (int j=0; j<COL; j++){
            mat[k][j] = rand()%MX;
        }
    }

    // Imprimir a matriz
    for(int k=0; k<LIN; k++){
        for (int j=0; j<COL; j++){
            printf("%d ",mat[k][j]);
        }
        printf("\n");
    }

    //Obter o menor e maior elementos
    unsigned menor = mat[0][0];
    unsigned maior = mat[0][0];

    for(int k=0; k<LIN; k++){
        for (int j=0; j<COL; j++){
            menor = (menor > mat[k][j])?mat[k][j]:menor;
            maior = (maior < mat[k][j])?mat[k][j]:maior;
        }
    }

    //Média
    float media = 0.0;
    for(int k=0; k<LIN; k++){
        for (int j=0; j<COL; j++){
            media += mat[k][j];
        }
    }
    media /= LIN*COL; // media = media / LIN*COL

    puts("======");
    printf("Menor : %u\n",menor);
    printf("Maior : %u\n",maior);
    printf("Média : %.2f\n",media);
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 100

int main(int argc, char *argv[]){
    
    if (argc!=3){
        printf("Use: \n\t\t %s <quantidadeLinhas> <quantidadeColunas>",argv[0]);
        exit(1);
    }

    // int mat[LIN][COL] = {0};
    int *mat = NULL;

    int lin = atoi(argv[1]);
    int col = atoi(argv[2]);
    
    // Exercício : criar função 
    mat = malloc(lin * col * sizeof(int));

    if (!mat){
        puts("Memória insuficiente.");
        exit(2);
    }

    // Exercício : criar função 
    srand(time(NULL));
    for (int k=0; k< lin*col; k++){
        *(mat+k) = rand() % MX;
    }

    // for (int k=0; k<LIN; k++){
    //     for (int j=0; j<COL; j++){
    //         mat[k][j] = rand()%MX;
    //     }
    // }

    puts("Matriz gerada: ");
    // for (int k=0; k<LIN; k++){
    //     for (int j=0; j<COL; j++){
    //         printf("[%p] %d ",&mat[k][j],mat[k][j]);
    //     }
    //     printf("\n");
    // }

    // Exercício : criar função 
    for (int k=0; k<lin*col; k++){
        if (!(k % col)) printf("\n");
        printf("[%p] %d ",mat+k, *(mat+k));
        
    }

    printf("\n");

    int i, c;
    puts("Qual a linha do elemento que deseja consultar? ");
    scanf("%d",&i);
    puts("Qual a coluna do elemento que deseja consultar? ");
    scanf("%d",&c);

    // Exercício : criar função 
    int elemento = *(mat + (col * i + c));
    int *pElem = mat + (col * i + c);

    printf("Elemento : [%p] %d\n",pElem, elemento);

    return 0;

}
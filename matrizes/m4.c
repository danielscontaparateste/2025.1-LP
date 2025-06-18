#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Exercício : incluir os valores de MX e INI para o usuário fornecer por linha de comando
#define MX 100
#define INI 0

int **alocarMemoria(int, int);
void popularMatriz(int **, int, int, int, int);
void imprimirMatriz(int **, int, int);
void liberarMemoria(int **, int);
void imprimirVetorPonteiros(int **, int);

int main(int argc, char **argv){

    if (argc!=3){
        printf("Use:\n\n\t\t%s <quantidadeLinhas> <quantidadeColunas>\n\n",*argv);
        exit(1);
    }

    int qtdLin = atoi(*(argv+1));
    int qtdCol = atoi(*(argv+2));

    int **pm = NULL;

    if (!(pm = alocarMemoria(qtdLin, qtdCol))){
        puts("Memória indisponível");
        exit(2);
    }

    srand(time(NULL));
    popularMatriz(pm, qtdLin, qtdCol, INI, MX );

    imprimirMatriz(pm, qtdLin, qtdCol);

    puts("==== Vetor de Ponteiros com o endereço das linhas ==== ");

    imprimirVetorPonteiros(pm, qtdLin);

    liberarMemoria(pm, qtdLin);
    
    return 0;
}

int **alocarMemoria(int qLin, int qCol){

    int **p = (int **) malloc(qLin * sizeof(int*));

    if (!p) return NULL;

    for (int k=0; k<qLin; k++){
        *(p+k) = (int *) malloc(qCol * sizeof(int));

        if (!(*(p+k))) return NULL;

    }
    return p;
}

void popularMatriz(int **p, int qLin, int qCol, int ini, int mx ){

    for (int k=0; k< qLin; k++){
        for (int j=0; j < qCol; j++){
            *(*(p+k) + j) = ini + rand() % mx;
        }
    }

}

void imprimirMatriz(int **p, int qLin, int qCol){

    for (int k=0; k< qLin; k++){
        for (int j=0; j < qCol; j++){
            printf("[%p] %4d ",*(p+k) + j, *(*(p+k) + j));
        }
        printf("\n");
    }
}

void liberarMemoria(int **p, int qLin){

    for (int k=0; k<qLin; k++){
         free(*(p+k));
    }
    free(p);
}

void imprimirVetorPonteiros(int **p, int qLin){
    for (int k=0; k< qLin; k++){
        
        printf("%p ",*(p+k));
        
    }
    printf("\n\n");
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *alocarMemoria(unsigned);
int **alocarMemoriaEnderecos(unsigned);
void preencherVetor(int *, unsigned, int, int);
void imprimirVetor(int *, unsigned);
void contarPares(int *, unsigned, unsigned *);
void obterPares(int *, unsigned, int *);
void imprimirVetorEnderecos(int **, unsigned);
void obterParesEnderecos(int *, unsigned, int **);

int main(int argc, char **argv){

    // ./program.e <qtdElementos>

    if (argc!=4){
        printf("Use: \n\t\t %s <quantidadeElementos> <valorInicial> <faixa>",*argv);
        exit(1);
    }

    unsigned qtd = atoi(*(argv+1));
    int ini = atoi(*(argv+2));
    int rg = atoi(*(argv+3));

    int *px = alocarMemoria(qtd);
    if (!px){
        puts("Memória indisponível.");
        exit(2);
    }

    srand(time(NULL));

    preencherVetor(px, qtd, ini, rg);

    imprimirVetor(px, qtd);

    unsigned qtdPares = 0;

    contarPares(px, qtd, &qtdPares);
    printf("Quantidade de Pares: %u\n",qtdPares);

    int *py = alocarMemoria(qtdPares);

    obterPares(px, qtd, py);

    puts("Elementos pares: ");
    imprimirVetor(py, qtdPares);

    int **pz = alocarMemoriaEnderecos(qtdPares);
    if (!pz){
        puts("Memória indisponível.");
        exit(3);
    }

    obterParesEnderecos(px, qtd, pz);

    puts("Endereços dos elementos pares: ");
    imprimirVetorEnderecos(pz, qtdPares);

    return 0;

}

int *alocarMemoria(unsigned q){
    int *p = (int *) malloc(q * sizeof(int));
    return p;
}

int **alocarMemoriaEnderecos(unsigned q){
    int **p = (int **) malloc(q * sizeof(int *));
    return p;
}

void preencherVetor(int *p, unsigned t, int inicial, int rg){
    for (int k=0; k<t; k++){
        *(p+k) = inicial + rand() % rg;
    }
}

void imprimirVetor(int *p, unsigned t){
    for (int k=0; k<t; k++){
        printf("[%p] %d\n",p+k, *(p + k));
    }
}

void imprimirVetorEnderecos(int **p, unsigned t){
    for (int k=0; k<t; k++){
        printf("[%p] %p\n",p+k, *(p + k));
    }
}

void contarPares(int *p, unsigned t, unsigned *pQtdPares){

    *pQtdPares = 0;

    for (int k=0; k<t; k++){
        if (!(*(p+k) % 2)){
            (*pQtdPares)++;
        }
    }

}

void obterPares(int *px, unsigned t, int *py){
    int j=0;
    for (int k=0; k<t; k++){
        if (!(*(px+k) % 2)){
           *(py + j) = *(px+k);
           j++; 
        }
    }
}


void obterParesEnderecos(int *px, unsigned t, int **pz){
    int j=0;
    for (int k=0; k<t; k++){
        if (!(*(px+k) % 2)){
           *(pz + j) = px+k;
           j++; 
        }
    }
}
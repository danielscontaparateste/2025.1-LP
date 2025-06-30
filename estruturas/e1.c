/*
    Código incompleto - vamos continuar na próxima aula. Tentem resolver em casa. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct alunos{
    float *pNotas;
    int qtdNotas;
    float media;
};

struct alunos *alocarMemoriaAlunos(int );
void definirQtdNotas(struct alunos *, int, int, int);
void imprimirQtdNotas(struct alunos *, int);
int alocarMemoriaNotas(struct alunos *, int);

int main(int argc, char **argv){

    if (argc!=4){
        printf("Use:\n\t\t %s <qtdAlunos> <minQtdNotas> <maxQtdNotas>\n\n",*argv);
        exit(1);
    }

    int qtdAlunos = atoi(*(argv+1));
    int qtdMinNotas = atoi(*(argv+2));
    int qtdMaxNotas = atoi(*(argv+3));

    struct alunos *als = alocarMemoriaAlunos(qtdAlunos);
    
    if (!als){
        puts("Memória indisponível");
        exit(2);
    }

    srand(time(NULL));


    definirQtdNotas(als, qtdAlunos, qtdMinNotas, qtdMaxNotas);

    imprimirQtdNotas(als, qtdAlunos);
    
    if (!(alocarMemoriaNotas(als, qtdAlunos))){
        puts("Memória indisponível para o vetor de notas de algum aluno");
        exit(3);
    }

    // lancarNotas(als, qtdAlunos);

    // calcularMedia(als, qtdAlunos);

    // imprimirNotas(als, qtdAlunos);

    return 0;
}


struct alunos *alocarMemoriaAlunos(int qtd){
    return malloc(qtd * sizeof(struct alunos));
}

void definirQtdNotas(struct alunos *p, int qa, int qmin, int qmax){
    for (int k=0; k<qa; k++){
        (p+k)->qtdNotas = qmin + rand() % (qmax-qmin + 1);  
    }
}

void imprimirQtdNotas(struct alunos *p, int qa){
    for (int k=0; k<qa; k++){
        printf("Aluno %d - Quantidade de Notas = %d\n", k, (p+k)->qtdNotas);
    }
}

int alocarMemoriaNotas(struct alunos *p, int qa){
    for (int k=0; k<qa; k++){
        (p+k)->pNotas = (float *) calloc((p+k)->qtdNotas, sizeof(float));
        if (!((p+k)->pNotas)) {
            return 0;
        }
    }
    return 1;
}
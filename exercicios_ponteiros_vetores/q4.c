#include <stdio.h>

#define TAM 50

#define FALSE 0
#define TRUE 1

void imprimirEndStr(char *);
void buscarCharStr(char *, char);

int main(){
    char str[TAM];
    char ch;

    puts("Digite a string");
    fgets(str,TAM,stdin);

    puts("Digite uma letra ");
    ch = getchar();

    printf("ch : %c\n\n",ch);

    imprimirEndStr(str);
    buscarCharStr(str,ch);

    return 0;

}

void imprimirEndStr(char *p){
    int k=0;
    while (*(p+k)!='\0'){
        printf("[%p] %c\n",p+k, *(p+k));
        k++;
    }
}

void buscarCharStr(char *p, char x){
    int k=0;
    char localizado = FALSE;
    while (*(p+k)!='\0'){
        if (x == *(p+k)){
            printf("%p\n",p+k);
            localizado = TRUE;
        }
        k++;
    }
    if (!localizado) printf("%c não existe em : %s\n",x, p);
}
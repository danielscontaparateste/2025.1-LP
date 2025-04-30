#include <stdio.h>
#include <string.h>

//strlen, strcmp, strcat

#define TAM 20

int main(){
    char str[TAM];

    puts("Digite as letras do seu nome: ");
    // for (int k=0; k<TAM; k++){
    //     scanf("%c",&str[k]); // str[k] = getchar();
    //     getchar();
    // }
    scanf("%s",str);

    puts("String: ");
    // for (int k=0; k<TAM; k++){
    int k=0;
    while(str[k]!='\0'){
        printf("%c",str[k]);
        k++;
    }
    printf("\n");

    printf("Uso do printf: %s\n",str);

    return 0;
}
#include <stdio.h>

int main(){

    int n1, n2, res;

    puts("Digite um número: ");
    scanf("%d",&n1);

    puts("Digite outro número: ");
    scanf("%d",&n2);

    // int res = n1 + n2;
    res = n1 + n2;

    printf("Resultado de %d + %d é %d\n",n1, n2, res);

    return 0;
}
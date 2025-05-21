#include <stdio.h>

int somar(int x, int y);
void imprimir(int x);

int main(){
    int a, b, c;

    int *pa, *pb, *pc;

    pa = &a;
    pb = &b;
    pc = &c;

    puts("Digite o primeiro valor: ");
    scanf("%d",pa);

    puts("Digite o segundo valor: ");
    scanf("%d",pb);

    // *pc = *pa + *pb; //  c = a + b;
    *pc = somar(*pa, *pb);

    // printf("Resultado: %d\n",*pc);
    imprimir(*pc);

    return 0;  
        
}

int somar(int x, int y){
    int r = x + y;
    return r;
}

void imprimir(int x){
    printf("Resultado : %d\n",x);
}
#include <stdio.h>
#include <math.h>

int main(){
     
    int x;
    int inv = 0;

    puts("Digite o número a ser invertido: ");
    scanf("%d",&x);

    int num = x;

    int qtd = 0;
    while (num){
        num = num / 10;
        qtd++;
    }

    num = x;
    int dig;
    while (num){
        dig = num % 10;
        inv = inv * 10 + dig;
        num = num / 10;
    }
    
    // Exercício : É possível implementar os dois laços (qtd e inverter) em apenas um único laço? 

    
    // int res = 0;
    // do{
    //     qtd++;
    //     res = num / pow(10,qtd);
    // }while(res != 0);

    // inverter

        
    printf("Qtd: %d\n", qtd);
    printf("Invertido : %d\n", inv);

    
    
    return 0;
}
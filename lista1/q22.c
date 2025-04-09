#include <stdio.h>

int main(){
     
    int x = 281; 

    int c, d, u;
    
    c = x / 100;
    d = (x % 100) / 10;
    u = (x % 100) % 10;

    int res = u * 100 + d * 10 + c;

    printf("Número: %d - Invertido: %d\n",x, res);

    // Exercício : adaptar para qualquer quantidade de dígitos em x. 
    
    return 0;
}
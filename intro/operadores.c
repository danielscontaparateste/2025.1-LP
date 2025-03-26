#include <stdio.h>

int main(){

    int x;
    int y = 2; 

    puts("Digite o valor de x: ");
    scanf("%d",&x);

    if (!(x % 2)&&(x>5)){
        puts("PAR");
    }

    int k = 0;

    puts("Digite k: ");
    scanf("%d",&k);

    if (k){
        puts("OI");
    }

    printf("R. expr. = %d\n",!(x % 2)&&(x>5));

    // y = x++;
    // y = ++x;

    // y = y * x++ + 1;
    // y *= x++ + 1;
    y *= ++x + 1;

    

    // x++; // x = x + 1; // x += 1; 

    printf("y = %d\n",y);
    printf("x = %d\n",x);

    return 0;
}
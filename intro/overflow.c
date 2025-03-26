#include <stdio.h>

int main(){
    unsigned char x = 255;

    printf("Antes do incremento: %hhu\n",x);
    x = x + 1;
    printf("Após o incremento: %hhu\n",x);

    return 0;
}
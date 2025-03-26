#include <stdio.h>

int main(){
    unsigned char status = 0x00;
    unsigned char mask = 0x01;

    unsigned pos; // unsigned int

    int c =0 ;

    do{    
        puts("Entre com uma posição de 1 a 8");
        scanf("%u",&pos);

        status =  status | (mask << (pos-1));

        printf("Status: %hhu\n",status);

        puts("0: continuar | 1 : parar");
        scanf("%d",&c);
    }while(!(c));

    return 0;
}


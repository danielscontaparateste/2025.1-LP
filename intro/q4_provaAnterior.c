#include <stdio.h>

#define QTD_DISPOSITIVOS 4

int main(){
    unsigned char signal = 0b11101011; 

    unsigned char mask = 0x01;
    unsigned char id;

    puts("Entre com o id do equipamento: ");
    scanf("%hhu",&id);

    (signal & (mask << (id-1)))?puts("Ligado"):puts("Desligado");
    (signal & (mask << (id-1 + QTD_DISPOSITIVOS)))?puts("Alto"):puts("Baixo");

    return 0;

}
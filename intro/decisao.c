#include <stdio.h>

int main(){

    

    char ch;

    puts("Digite a opção: ");
    scanf("%c",&ch);

    getchar();

    switch(ch){
        case 'x':
            puts("Opção 1");
        break;
        case 'z':
        case 'y':
            puts("Opção 2");
        break;    
        default:
            puts("Opção Inválida");
    }

    char a;
    puts("Digite outro caractere: ");
    scanf("%c",&a);

    printf("a = %c\n",a);

    // int a; 

    // scanf("%d",&a);

    // switch(a){
    //     case 10:
    //         puts("OI");
    //     break;
    //     case 20:
    //         puts("Hello");
    //     break;
    //     default:
    //         puts("Opção Inválida");
    // }

    // scanf("%d",&a);

    // if (a < 16){
    //     puts("Não vota e não dirige");
    // }else if (a<18){
    //     puts("Vota e não dirige");
    // }else{
    //     puts("Vota e dirige");
    // }

    // a += (a>10)?2:0;

    // if (a>10){
    //     a += 2; // a = a * 2;
    // }


    // b = (a>10)?2 * a:a / 2;

    // if (a>10){
    //     b =  2 * a;
    // }else{
    //     b = a / 2;
    // }

    // (a>10)?puts("Maior"):puts("Menor");

    // if (a>10)
    //     puts("Maior");
    // else{
    //     puts("Menor");
    // }
    
    
    // printf("a = %d\n",a);



    return 0;
}
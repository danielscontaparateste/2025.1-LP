#include <stdio.h>

int main(){

    char x;

    printf("char: %lu byte(s)\n",sizeof(x));
    printf("unsigned char: %lu byte(s)\n",sizeof(unsigned char));
    printf("int: %lu byte(s)\n",sizeof(int));
    printf("short int: %lu byte(s)\n",sizeof(short int));
    printf("long int: %lu byte(s)\n",sizeof(long int));
    printf("float: %lu byte(s)\n",sizeof(float));
    printf("double: %lu byte(s)\n",sizeof(double));
    printf("long double: %lu byte(s)\n",sizeof(long double));
    

    return 0;

}
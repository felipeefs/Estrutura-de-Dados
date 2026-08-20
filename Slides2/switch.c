#include <stdio.h>

int main(void){
    /*
    No switch, ele sempre vai descendo as condições até ele encontrar um break;

    O default, caso não tenha nenhum break ou nenhum case for assionado, ele sempre irá ocorrer
    */
    int i;
    scanf("%d", &i);

    switch(i){
    case 1:
    case 2:
        printf("Igual a 1 ou 2\n");

    case 3:
    case 4:
        printf("Menor que 5\n");
        break;
    
    case 5:
        printf("Igual a 5\n");
        break;
    
    default:
        printf("Menor que 0 ou maior que 5\n");
    }
}
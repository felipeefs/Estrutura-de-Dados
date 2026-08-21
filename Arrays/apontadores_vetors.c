#include <stdio.h>

int main(void) {
    int V[5] = {100,200,300,400,500};
    
    printf("V[0]: %d\n", V[0]);
    printf("*V: %d\n", *V); //valor do V[0] armazenado no apontador

    printf("&V[0]: %p\n", &V[0]); //endereço do apontador
    printf("V: %p\n", V); //V já é um apontador para V[0]

    return 0;
}
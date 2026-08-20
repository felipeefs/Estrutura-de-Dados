#include <stdio.h>

int main(void) {
    int largura = 17, precisao = 6;
    
    printf("%*d \n", largura, 100);
    
    printf("%*.*f \n", largura, precisao, 3.1416);
    
    return 0;
}
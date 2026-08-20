#include <stdio.h>
#include <math.h>
/*
0: Usa zeros ao invés de espaços para alinhar à direita
–: Alinha à esquerda
+: Sempre acrescenta um sinal + ou – antes de número
espaço: Acrescenta um espaço antes de número positivo*/

int main(void) {
    int i = 13, j = -13;
    
    printf("0: >%010d< >%010d< \n", i, j);
    printf("-: >%-10d< >%-10d< \n", i, j);
    printf("+: >%+d< >%+d< \n", i, j);
    printf(" : >% d< >% d< \n", i, j);
    
    int k = printf(" : >%016lf< \n", M_PI);
    
    printf("k=%d\n",k);
    
    return 0;
}
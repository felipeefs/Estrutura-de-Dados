#include <stdio.h>
/*A conversão é chamada de casting, e ela nunca converte a variável em si em outra, mas sim a expressão do momento*/
int main(void){
    (long) 'H'+5.0;
    double x, y;
    x = (double) ((int) y+1);
    (float) (x=77);


    long l = 1234567890;
    float f = 3.1416;
    printf("l+f %.17g\n",l+(double)f);
    return 0;
}
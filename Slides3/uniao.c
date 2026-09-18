#include <stdio.h>
int main(void) {
    
    union int_or_float {
        //Pode armazenar mais de uma variavel no mesmo lugar (uma de cada vez)
        //Usada quando o tipo de váriavel pode mudar
        int i;
        float f;
    };
    
    union int_or_float n;
    
    n.i = -123456789;
    printf("%d %e\n", n.i, n.f);

    n.f = 1234.0;
    printf("%d %f\n", n.i, n.f);


    
    
    return 0;
}
#include <stdio.h>

int main(void){
    /* Quando o operador é pré-posto, o objeto é modificado antes de
    dar valor à expressão.
    
    Quando o operador é pós-posto, o objeto é modificado depois de
    dar valor à expressão.*/
    int i = 5;
    printf("i++ %d\n", i++);
    printf("i após: %d\n", i);
    
    i = 5;
    printf("++i %d\n", ++i);
        
    i = 5;
    printf("i-- %d\n", i--);

    i = 5;
    printf("--i %d\n", --i);
    return 0;
    
}
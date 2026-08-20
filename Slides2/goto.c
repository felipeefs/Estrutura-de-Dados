#include <stdio.h>

int main(void){
    int i = 0;
    while (i <= 5) {
        i = i+1;

        if (i == 3)
            goto aqui; //Quando i for igual a 3, o goto leva o código para a instrução "aqui"

        printf("i %d\n",i);
    }    
    printf("i depois do while %d\n",i);
    
    aqui: 
        return 0; //instrução
    
}
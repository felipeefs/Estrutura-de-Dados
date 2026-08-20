#include <stdio.h>

int main(void){
    int i;
    for( i = 0; i<10; i++){ //Ao omitir o valor de i no inicio ele recebe 0
        printf("%d\n", i);
    }
    /*
    for( ; ; ){ //O primeiro recebe 0, o segundo recebe 1(True), 
        printf("infito\n");
    }
    */
    
    int j = 6;
    for (int j=0 ; j<10 ; j++){ 
        printf("for %d\n", j); //Lembre-se que dentro de um bloco uma váriavel de mesmo nome pode assumir outro valor
    }
    printf("j %d\n", j);

    return 0;
    

}
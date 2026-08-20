#include <stdio.h>

int main(void){
    int var = 0;
    //O do faz com que a execução ocorra pelo menos uma vez antes do teste do while acontecer
    do{
        printf("%d\n", var);
        var += 1;
    } while (var<=10);  

    int i = 0;
    do{
        printf("i é igual a: %d\n", i); //Nesse caso ele só ocorre uma vez, visto que i já é menor que 10
        i -= 1;
    } while (i>10);  


}
#include <stdio.h>

int break_c(void){
    int i = 0;
    while (i <= 5) {
        i = i+1;

        if (i == 3)
            break; //Quebra o loop na hora
        
        printf("i %d\n",i);
        }
        
    printf("i depois do while %d\n",i);
    return 0;
    
}

int continue_c(void){
    int i = 0;
    while (i <= 5) {
        i = i+1;

        if (i == 3)
            continue; //Volta no ponto inicil do loop
        
        printf("i %d\n",i);
        }
        
    printf("i depois do while %d\n",i);
    return 0;

}


int main(){
    break_c();
    continue_c();

}
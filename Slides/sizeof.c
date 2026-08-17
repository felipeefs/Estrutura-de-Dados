/*O sizeof serve para observar quantos bytes são necessários para armazenar uma variável*/
#include <stdio.h>

int main(void){
    printf("%ld\n", sizeof(int)); //Usado para paravras especiais
    int x;
    printf("O tamanho de x é: %ld\n", sizeof(x));
    printf("%ld\n", sizeof(5+9));


}
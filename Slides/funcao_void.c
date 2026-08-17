#include <stdio.h>

void f(){
    printf("A função é f()\n");
}

int main(void){
    f(); //executa a função void, que printa
    //x = f() **ERRO pois a void não pode ser "entregue para nenhuma variavel"
    return 0;
}
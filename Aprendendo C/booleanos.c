/* Em C não existem booleanos (True e False, logo usa-se o 0 para False, e qualquer outro inteiro para verdadeiro)*/
#include <math.h>
#include <stdio.h>

int booleanos(int a){
    if (a){
        printf("Verdadeiro\n");
    }
    else{
        printf("Falso\n");
    }
}

int main(){
    int i = 1;
    int j = 0;

    booleanos(i);
    booleanos(j);

}
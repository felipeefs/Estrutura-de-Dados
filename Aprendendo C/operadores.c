/* Para compilar um codigo em que haja operação use: "gcc operadores.c -o operadores -lm" */

#include <stdio.h>
#include <math.h>

double potenciacao(int n, int e){
    double potencia = pow(n, e);
    return potencia;
}

int contas(int a, int b){
    printf("A soma é: %d\n", a + b);
    printf("A subtração é: %d\n", a - b);
    printf("A multiplicação é: %d\n", a * b);
    printf("A divisão é: %d\n", a / b); //Para que ocorra uma divisão decimal, use os numeros declarados como 10.0 e 2.0
    printf("O resto é: %d\n", a % b);
}


int main(){
    int x = 4;
    int e = 2;
    printf("%f\n", potenciacao(x, e));

    int a = 10;
    int b = 2;
    contas(a, b); 

    return 0;
}
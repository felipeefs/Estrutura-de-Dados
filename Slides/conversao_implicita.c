#include <stdio.h>
/*Inteiros são convertidos em outro tipo de inteiro a depender da conversão*/


int main(void){
    int i = 11;
    float r = i/2; //Ambos são inteiros, logo ocorre uma divisão inteira
    float s = i / 2.0; //i é inteiro e 2.0 é um double, logo o i é convertido em double
    printf("r=%f, s=%f\n", r,s);


    long l = 1234567890;
    float f = 3.1416;
    printf("l+f = %f\n", l+f); //Nrsse caso, pela ordem de conversão, o long é transformado em float

    int k = -1;
    unsigned j = 100;
    if(k<j){ //Nesse caso, quando faz a comparação o k vira um unsigned, logo ele vira um numero maior que o j, fazendo com que k>j
        printf("%d < %u\n", k,j);
        }
    else{
        printf("%u < %d\n", j, k);
        printf("O valor de k após a conversão é: %u\n", (unsigned)k);
    }
    return 0;



}
#include <stdio.h>

unsigned int_unsigned(void){
    /*O int: 32 bits um int pode armazenar númerosentre −2**31 e 2**31 − 1 (entre −2.147.483.648 e 2.147.483.647).
    O unsigned: 32 bits um unsigned int pode armazenar números entre 0 e 2**32 − 1 (entre 0 e 4.294.967.295)
    */
   int normal = -1;

   // Conversão de int para unsigned
   unsigned int sem_sinal = (unsigned int) normal;

   //%u para unsigned:
   printf("O valor normal do inteiro é: %d\n", normal);
   printf("O valor convertido para unsigned é: %u\n", sem_sinal);
}



char caracteres(void){
    /*cada caracter ocupa um byte (8 bites), e pode ser lido também como um inteiro*/
    char x = 'a';
    printf("Como caracter: %c\n",x);
    printf("Como inteiro: %d\n",x);

    x += 100;
    printf("Como caracter: %c\n",x);
    printf("Como inteiro: %d\n",x);    
}

signed char signed_char(void){
    /*O signed é como se fosse a variavel normal, ele diz que pode ser um número negativo e positivo*/
    signed char x = 'a';
    printf("O caracter como signed char: %d\n", x);

}

int main(void){
    int_unsigned();
    caracteres();
    signed_char();

    /*MODIFICADORES*/
    short int x = 12; //O short diminui a metade dos bytes de um int comum (ficam 2 bytes), usado para vetores muito grandes
    long int y = 13; //O long dobra os bytes de um int comum (ficam 8 bytes)
    long double z = 14; //Ele aumenta 80, 96, 128 ou mais bits de um double.
    long long int j = 1; //Ele pode reservar 8 bytes para um inteiro, mais usado pois alguns sistemas operacionais não "entende" apenas um long



    
}
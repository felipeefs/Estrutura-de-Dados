#include <stdio.h>


int variaveis(void){
    char _idade1[] = "10 anos"; //Você pode criar uma variavel começando com _, mas não pode começa-la por um numero
    /*Nesse caso usa-se um vetor, pois uma frase não pode ser armazenada em um unico char(caractere)*/
    printf("%s\n", _idade1);
}


int main(void){
    int x = 0; //x é um nome/identificador, você cria ele e da um nome a ele (variavel), tal como o NOME DE UMA FUNÇÃO

    /*
    while (x<10)
    ; //loop infinito
    */
    variaveis();
    return 0;
}

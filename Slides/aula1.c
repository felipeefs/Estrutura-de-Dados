#include <stdio.h>
#define pi 3.1415
#define mess "mess agora é uma mensagem definida"


int variaveis(void){
    char _idade1[] = "10 anos"; //Você pode criar uma variavel começando com _, mas não pode começa-la por um numero
    /*Nesse caso usa-se um vetor, pois uma frase não pode ser armazenada em um unico char(caractere)*/
    printf("%s\n", _idade1); //usa-se %s para printar strings (palavras com mais de um caracter)

    int y = 1e3;
    printf("O número y em notação ciêntifica é: %d\n ", y);
}

int teste_definicoes(void){
    double mult = pi * 2.0;
    printf("A dobro de pi é: %f\n: ", mult);

}

int escopo(void){
   /*Nesse caso, quando você cria uma variavel dentro de um escopo, ela fica lá dentro (seu valor não muda)*/ 
    int i = 1, x = 2, z = 3;

    if(i == 1){
        int x = 20;
        int y = 80;
        z = 30;
        printf("x=%d y=%d z=%d\n", x, y, z);
    }
    printf("x=%d, z=%d\n", x, z);
    //printf("y %d\n",y); // Erro. ---> pois o y está declarado dentro do if
}

int main(void){
    int x = 0; //x é um nome/identificador, você cria ele e da um nome a ele (variavel), tal como o NOME DE UMA FUNÇÃO

    /*
    while (x<10)
    ; //loop infinito
    */

    //variaveis();
   // teste_definicoes();
    escopo();
    return 0;
}

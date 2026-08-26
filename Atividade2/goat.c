#include <stdio.h>
#include <string.h>
#include <math.h>
#define max_palavras 1000
#define max_caracteres 100

char comeca_vogal(char frase_total[], int posicao_atual){

}




int main(){
    // Ler a frase_total, ver o tamanho dela e criar um vetor para a mesma
    char frase_total[200000]; 
    char frase[max_palavras][max_caracteres];
    int num_palavras = 0;

    scanf("%[^\n]", frase_total); //Lê até a quebra de linha ao digitar

    //Cria uma matriz frase, em que cada elemento é uma palavra
    char *palavra = strtok(frase_total, " ");
    printf("%c\n", *palavra);
    while(palavra != NULL && num_palavras < max_palavras){ 
        int j;
        for(j=0; palavra[j] != '\0'; j++){
            frase[num_palavras][j] = palavra[j];
        }
        frase[num_palavras][j] = '\0';
        num_palavras++;
        palavra = strtok(NULL, " ");
    }

    //Analisa palavra por palavra e adiciona as regras de Goat Latin
    for (int i = 0; i < num_palavras; i++) {
        printf("frase[%d] = %s\n", i, frase[i]);
        


    }
    
    return 0;




}


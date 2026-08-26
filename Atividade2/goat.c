#include <stdio.h>
#include <string.h>
#include <math.h>
#define max_palavras 1000
#define max_caracteres 100

char comeca_vogal(int i, char frase[][max_caracteres]){
    int posicao_final = 0;
    for(int j = 0; frase[i][j] != '\0'; j++){
        posicao_final++;
    }
    frase[i][posicao_final] = 'm';
    frase[i][posicao_final + 1] = 'a';
    frase[i][posicao_final + 2] = '\0';
    printf("%d\n", posicao_final);
    

}




int main(){
    // Ler a frase_total, ver o tamanho dela e criar um vetor para a mesma
    char frase_total[200000]; 
    char frase[max_palavras][max_caracteres];
    int num_palavras = 0;

    scanf("%[^\n]", frase_total); //Lê até a quebra de linha ao digitar

    //Cria uma matriz frase, em que cada elemento é uma palavra
    char *palavra = strtok(frase_total, " ");
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
        
        if(frase[i][0] == 'a' || frase[i][0] == 'e' || frase[i][0] == 'i' || frase[i][0] == 'o' || frase[i][0] == 'u' || frase[i][0] == 'A' || frase[i][0] == 'E' || frase[i][0] == 'O' || frase[i][0] == 'I' || frase[i][0] == 'U')
            comeca_vogal(i, frase);

        printf("frase[%d] = %s\n", i, frase[i]);


            for(int j =0; frase[i][j] != '\0'; j ++){
                printf("A letra da palavra: %c\n", frase[i][j]);

            }



    }
    
    return 0;




}


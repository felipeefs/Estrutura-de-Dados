#include <stdio.h>
#include <string.h>
#include <math.h>

char comeca_vogal(){
    //Adiciona "ma" ao final da palavra

}




int main(){
    // Ler a frase, ver o tamanho dela e criar um vetor para a mesma
    char frase[200000]; //Pelos cálculos por bytes, esse é o tamanho máximo que o vetor poderá ter no exercício
    scanf("%[^\n]", frase); //Lê até a quebra de linha ao digitar

    /*  
    printf("%s\n", frase);
    for(int i = 0; frase[i] != '\0'; i++)
        printf("%c\n", frase[i]); 
    */
    for(int i = 0; i < strlen(frase); i++)
        printf("%c\n", frase[i]); 

    printf("%d\n", strlen(frase));

    //Loop que le a frase e até que ache um espaço faz operações na palavra, quando acha um espaço da um break para recomeçar loop?
    for(int i = 0; frase[i] != " " && i < strlen(frase); i++){
        if(frase[0] == 'a' || frase[0] == 'e' || frase[0] == 'i' || frase[0] == 'o' || frase[0] == 'u' || frase[0] == 'A' || frase[0] == 'E' || frase[0] == 'O' || frase[0] == 'I' || frase[0] == 'U')
            comeca_vogal(frase);
        


    }

}


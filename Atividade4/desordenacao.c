#include <stdio.h>
#include <stdlib.h>


int main(){
    long entradas;
    scanf("%ld", &entradas);

    while(entradas > 0){
        int j, k;
        scanf("%d %d", &j, &k);

        int tamanho = j + 2; //Todas as letras + \n e \0

        //Cria um ponteiro para ponteiro, em que armazena k elementos para depois adiciona-los
        char** palavras = malloc(k * sizeof(char*));

        for(int i = 0; i< k; i++){
            palavras[i] = malloc(tamanho * sizeof(char));
        }

        for(int i = 0; i<k; i++){
            //fgets(palavras[i], tamanho, stdin);
            scanf(" %[^\n]", palavras[i]);
        }
        for(int i = 0; i<k; i++){
            printf("O DNA é: %s\n", palavras[i]);
        }

        







        entradas --;
    }


}
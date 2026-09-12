#include <stdio.h>
#include <stdlib.h>

void contar_desordenação(char **palavras, long *ocorrencias, int j, int k){
    long soma = 0;
    int t = 0;
    for(int i = 0; i < k; i++){
        for(t = 0; t < j - 1; t++){ //Menos 1 no j, porque o ultimo elemento nunca precisa ser comparado
            printf("A letra atual tem tamanho: %d, e a proxima tem %d\n", (int)palavras[i][t], (int)palavras[i][t+1]);
            if(((int)palavras[i][t]) > ((int)palavras[i][t+1])){
                soma ++;
            }
        }
        ocorrencias[i] = soma;
        soma = 0;
    }
}

int main(){
    long entradas;
    scanf("%ld", &entradas);

    while(entradas > 0){
        int j, k;
        scanf("%d %d", &j, &k);

        int tamanho = j + 2; //Todas as letras + \n e \0

        //Cria um ponteiro para ponteiro, em que armazena k elementos para depois adiciona-los
        char** palavras = malloc(k * sizeof(char*));
        long* ocorrencias = malloc(k * sizeof(long));

        //Adiciona em cada lugar de memória desse ponteiro anteriormente criado espaço para armazenar uma string
        for(int i = 0; i< k; i++){
            palavras[i] = malloc(tamanho * sizeof(char));
        }

        for(int i = 0; i<k; i++){
            //fgets(palavras[i], tamanho, stdin);
            scanf(" %[^\n]", palavras[i]);
        }

        contar_desordenação(palavras, ocorrencias, j, k);

        for(int i = 0; i<k; i++){
            printf("O DNA é: %s; com tamanho %ld\n", palavras[i], ocorrencias[i]);
            printf("A letra do DNA é: %c\n", palavras[i][i]);



        }

        entradas --;
    }


}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define max_palavras 1000
#define max_caracteres 100

int remover_numeros(char frase[][max_caracteres], int i, int soma){
    for(int j =0; frase[i][j] != '\0'; j++){
        //Para remoção de números:
        if(frase[i][j] >= '0' && frase[i][j] <= '9'){
            char soma_str[6];
            int acumulador = 0;

            while(frase[i][j] >= '0' && frase[i][j] <= '9'){
                soma_str[acumulador] = frase[i][j];
                acumulador ++;

                //Sobrescreve os números encontrados (sempre voltando uma casa, logo o while só para quando não tem números lado a lado)
                for(int k = j;frase[i][k] != '\0'; k++){
                    frase[i][k] = frase[i][k+1];
                }    
            }

            soma_str[acumulador] = '\0';
            soma += atoi(soma_str);
            j--; 
        }
    }
    //printf("A soma é %d\n", soma);
    return soma;

}

void remover_especiais(char frase[][max_caracteres], int i){
    for(int j =0; frase[i][j] != '\0'; j++){
    //Para a remoção de caracteres especiais, sobrescreve-los:
        if(!((frase[i][j] >= 'a' && frase[i][j] <= 'z') ||(frase[i][j] >= 'A' && frase[i][j] <= 'Z'))){
        for(int k = j; frase[i][k] != '\0'; k++){
            frase[i][k] = frase[i][k+1];
            }
            j--; //Diminui 1, porque quando arrasta todos para a esquerda, o caractere que está a direita do especial precisa ser verificado
            //printf("frase após tirar especial: %s\n", frase[i]);
        }        

    }
}

int achar_posicao_final(int i, char frase[][max_caracteres]){ 
    //Acha a posição final de uma palavra (seu tamanho), antes de passar por modificações
    int posicao_final = 0;
    for(int j = 0; frase[i][j] != '\0'; j++){
        posicao_final++;
    }
    return posicao_final;
}

void comeca_vogal(int i, char frase[][max_caracteres], int posicao_final){
    //Ao achar uma palavra que começa com vogal, percorre toda ela até achar a posição final para adicionar "ma"
    frase[i][posicao_final] = 'm';
    frase[i][posicao_final + 1] = 'a';
    frase[i][posicao_final + 2] = '\0';
}

void comeca_consoante(int i, char frase[][max_caracteres], int posicao_final){
    //Adiciona a primeira letra ao final da palavra, depois retira a primeira letra do começo através de um loop. Ao final adiciona o "ma"
    frase[i][posicao_final] = frase[i][0];

    for(int j = 0; frase[i][j] != '\0'; j++){
        frase[i][j] = frase[i][j+1];
    }

    frase[i][posicao_final] = 'm';
    frase[i][posicao_final + 1] = 'a';
    frase[i][posicao_final + 2] = '\0';

}

void adicionar_sufixo(int i, char frase[][max_caracteres], int n_sufixo){
    //Descobre qual é a posição final atual após adicionar o sufixo "ma", e a posicao_final inicial se torna o n_sufixo que será adicionado de sufixos "aaaa"
    int posicao_final = achar_posicao_final(i, frase);

    for(int j = posicao_final ; j < n_sufixo + posicao_final ; j++){ 
        frase[i][j] = 'a';
    }

    frase[i][posicao_final + n_sufixo] = '\0';
}

void imprir_resultados(char frase[][max_caracteres], int num_palavras, int soma){
    if(soma != 1)
        printf("%d goats say:", soma);
    else
        printf("%d goat says:", soma);

    for (int i = 0; i < num_palavras; i++) {
        if(frase[i][0] != '\0')
            printf(" %s", frase[i]);
    }
    printf("\n");
}


int main(){
    // Ler a frase_total, ver o tamanho dela e criar um vetor para a mesma
    char frase_total[10000]; 
    char frase[max_palavras][max_caracteres];

    while (scanf(" %[^\n]", frase_total) != EOF){  //Lê até a quebra de linha ao digitar
        int num_palavras = 0;
        int soma = 0;

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
            //printf("frase[%d] = %s\n", i, frase[i]);
            
            soma = remover_numeros(frase, i, soma);
            remover_especiais(frase, i);
            
            int posicao_final = achar_posicao_final(i, frase);

            if(frase[i][0] == 'a' || frase[i][0] == 'e' || frase[i][0] == 'i' || frase[i][0] == 'o' || frase[i][0] == 'u' || frase[i][0] == 'A' || frase[i][0] == 'E' || frase[i][0] == 'O' || frase[i][0] == 'I' || frase[i][0] == 'U'){
                comeca_vogal(i, frase, posicao_final);
                //printf("frase[%d] = %s\n", i, frase[i]);
            }

            else if(frase[i][0] != '\0')
                comeca_consoante(i, frase, posicao_final);

            adicionar_sufixo(i, frase, posicao_final);

        }
        imprir_resultados(frase, num_palavras, soma);
    }
    return 0;
}
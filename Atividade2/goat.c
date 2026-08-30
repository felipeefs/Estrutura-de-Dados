#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max_palavras 1000
#define max_caracteres 1200

void remover_numeros(char p[]){
    for(int j = 0; p[j] != '\0'; j++){
            if(p[j] >= '0' && p[j] <= '9'){
                while(p[j] >= '0' && p[j] <= '9'){
                    for(int k = j; p[k] != '\0'; k++){
                        p[k] = p[k+1];
                    }    
                }
                j--; 
            }
        }
    }
void remover_especiais(char p[]){
    for(int j = 0; p[j] != '\0'; j++){
            if(!((p[j] >= 'a' && p[j] <= 'z') ||(p[j] >= 'A' && p[j] <= 'Z'))){
                for(int k = j; p[k] != '\0'; k++){
                    p[k] = p[k+1];
                }
                j--; 
            }        
        }
    }

int achar_posicao_final(char p[]){ 
    //Acha a posição final de uma palavra (seu tamanho), antes de passar por modificações
    int posicao_final = 0;
    for(int j = 0; p[j] != '\0'; j++){
        posicao_final++;
    }
    return posicao_final;
}

void comeca_vogal(char p[], int posicao_final){
    //Ao achar uma palavra que começa com vogal, percorre toda ela até achar a posição final para adicionar "ma"
    p[posicao_final] = 'm';
    p[posicao_final + 1] = 'a';
    p[posicao_final + 2] = '\0';
}

void comeca_consoante(char p[], int posicao_final){
    //Adiciona a primeira letra ao final da palavra, depois retira a primeira letra do começo através de um loop. Ao final adiciona o "ma"
    char primeira_letra = p[0];

    for(int j = 0; p[j] != '\0'; j++){
        p[j] = p[j+1];
    }

    p[posicao_final - 1] = primeira_letra;

    p[posicao_final] = 'm';
    p[posicao_final + 1] = 'a';
    p[posicao_final + 2] = '\0';

}

void adicionar_sufixo(char p[], int n_sufixo){
    //Descobre qual é a posição final atual após adicionar o sufixo "ma", e a posicao_final inicial se torna o n_sufixo que será adicionado de sufixos "aaaa"
    int posicao_final = achar_posicao_final(p);

    for(int j = posicao_final ; j < n_sufixo + posicao_final ; j++){ 
        p[j] = 'a';
    }

    p[posicao_final + n_sufixo] = '\0';
}

/*
void imprir_resultados(char frase[][max_caracteres], int num_palavras, long long soma){
    if(soma != 1)
        printf("%lld goats say:", soma);
    else
        printf("%lld goat says:", soma);

    for (int i = 0; i < num_palavras; i++) {
        if(frase[i][0] != '\0')
            printf(" %s", frase[i]);
    }
    printf("\n");
}
    */


int main(){
    // Ler a frase_total, ver o tamanho dela e criar um vetor para a mesma
    char frase_total[200000]; 

    while (fgets(frase_total, sizeof(frase_total), stdin) != NULL){  //Lê até a quebra de linha ao digitar
        long long soma = 0;

        //Descobre-se a soma total dos números presentes na frase
        for(int j = 0; frase_total[j] != '\0'; j++){
            if(frase_total[j] >= '0' && frase_total[j] <= '9'){
                long long num_acumulado = 0;
                while(frase_total[j] >= '0' && frase_total[j] <= '9'){
                    num_acumulado = num_acumulado * 10 + (frase_total[j] - '0');
                    j++;
                }
                soma += num_acumulado;
                j--; 
            }
        }

        //Impressões:
        if(soma != 1)
            printf("%lld goats say:", soma);
        else
            printf("%lld goat says:", soma);

        char *palavra = strtok(frase_total, " \n\r");

        while(palavra != NULL){

            char p[200000]; 
            int j;

            for(j = 0; palavra[j] != '\0'; j++){
                p[j] = palavra[j]; 
            }
            p[j] = '\0';           

            remover_numeros(p);
            remover_especiais(p);
            
            int posicao_final = achar_posicao_final(p);

            if (posicao_final>0){
                if(p[0] == 'a' || p[0] == 'e' || p[0] == 'i' || p[0] == 'o' || p[0] == 'u' || p[0] == 'A' || p[0] == 'E' || p[0] == 'O' || p[0] == 'I' || p[0] == 'U'){
                    comeca_vogal(p, posicao_final);
                    //printf("frase[%d] = %s\n", i, frase[i]);
                }
            

            else{
                comeca_consoante(p, posicao_final);
            }

                adicionar_sufixo(p, posicao_final);

                printf(" %s", p);

            }
            palavra = strtok(NULL, " \n\r");
        }
        
        printf("\n");

    } // O while do fgets fecha aqui.

    return 0; // O return 0 vai no final da main.
}
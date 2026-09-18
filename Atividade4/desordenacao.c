#include <stdio.h>
#include <stdlib.h>

void contar_desordenação(char **palavras, long *ocorrencias, int j, int k){
    long soma = 0;
    int t = 0;
    for(int i = 0; i < k; i++){ //Loop para cada palavra
        for(t = 0; t < j; t++){ //Loop para cada letra fixa
            //printf("A letra atual tem tamanho: %d, e a proxima tem %d\n", (int)palavras[i][t], (int)palavras[i][t+1]);
            for(int v = t + 1; v < j; v++){
                if(((int)palavras[i][t]) > ((int)palavras[i][v])){ //Tenho que comparar uma letra fixa, nao as do lado
                    soma ++;
                }
            }
        }
        ocorrencias[i] = soma;
        soma = 0;
    }
}

void ordenar_vetores(char **palavras, long *ocorrencias, int l, int m, int k){
    //Função para separar vetores, e ordena-los
    int n1 = m - l + 1;
    int n2 = k - m;

    long esq_oco[n1], dir_oco[n2];
    char *esq_pala[n1], *dir_pala[n2];

    //Divide os vetores em dois
    for (int i = 0; i <n1; i++){
        esq_oco[i] = ocorrencias[l + i];
        esq_pala[i] = palavras[l + i];
    }

    for(int j = 0; j <n2; j++){
        dir_oco[j] = ocorrencias[m + 1 + j];
        dir_pala[j] = palavras[m + 1 + j];
    }

    int i = 0, j = 0, f = l;

    //Intercala os vetores pelo seu tamanho
    while(i < n1 && j < n2){
        if(esq_oco[i] <= dir_oco[j]){
            ocorrencias[f] = esq_oco[i];
            palavras[f] = esq_pala[i];
            f++;
            i++;
        }
        else{
            ocorrencias[f] = dir_oco[j];
            palavras[f] = dir_pala[j];
            f++;
            j++;
        }
    }

    //Aloca os elementos que sobraram
    while (i<n1){
        ocorrencias[f] = esq_oco[i];
        palavras[f] = esq_pala[i];
        i++;
        f++;
    }
    while(j<n2){
        ocorrencias[f] = dir_oco[j];
        palavras[f] = dir_pala[j];
        j++;
        f++;
    }
}

void merge_sort(char **palavras, long*ocorrencias, int l, int k){
    //Função de ordenação mergesort, que ordena vetores os quebrando em partes
    if (l < k){
        int m = l + (k - l) / 2;
        
        merge_sort(palavras, ocorrencias, l, m);
        merge_sort(palavras, ocorrencias, m +1, k);

        ordenar_vetores(palavras, ocorrencias, l, m, k);
    }
}

int main(){
    int entradas;
    scanf("%d", &entradas);

    while(entradas > 0){
        scanf("\n");
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
            scanf(" %[^\n]", palavras[i]);
        }

        contar_desordenação(palavras, ocorrencias, j, k);
        merge_sort(palavras, ocorrencias, 0, k -1);

        for(int i = 0; i<k; i++){
            printf("%s\n", palavras[i]);
        }
        printf("\n");

        entradas --;
    }
}
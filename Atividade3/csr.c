#include <stdio.h>
#include <stdlib.h>

int comparar_inteiros(const void *a, const void *b){
    //Compara dois inteiros da lista, para serem ordenados
    return (*(int *)a) - (*(int *)b);
}

void realocar_vetorR(int *R, int k, int *L){
    //Preenche o vetor R a partir da ocorrencia das linhas da matriz (tal linhas que estão guardadas em L)
    R[0] = 0; //O vetor R sempre começa zerado

    int posicao = 1;
    int ocorrencia = 1;
    for(int f = 0; f < k; f++){
        if(L[f] == L[f+1] && (L[f]+1) == posicao){
            ocorrencia += 1;
        }
        else if(L[f] != L[f+1] && (L[f]+1) == posicao){
            R[posicao] = ocorrencia;
            ocorrencia += 1;
            posicao += 1;
        }
        else{
            R[posicao] = ocorrencia - 1;
            posicao += 1;
            //atual = L[f];
            f --;
        }
    }
}

int procurar_Nnulos(int *R, int i){
    //Na linha em que queremos achar o valor, verifica-se se há elementos não nulos e devolve sua quantidade
    return R[i+1] - R[i];   

}

int procurar_coluna(int *R, int *C, int j, int i){
    //A partir dos valores de R, procura-se a ocorrência de j na lista das colunas (C), e devolve-se a posicção em que ele foi encontrado
    for(int f = R[i]; f < R[i+1] - 1; f++){
        if (C[f] == j){
            return f;
        }
        else
            return 0; //Devolve-se um booleano False, caso contrário
    }
}




    
int main(){
    int k, i_max = 0;
    scanf(" %d", &k);
    int *A = malloc(k * sizeof(int)); //Armazena os valores de x
    int *C = malloc(k * sizeof(int)); //Armazena os valores das colunas
    int *L = malloc(k * sizeof(int)); //Armazena os valores das linhas

    if(A == NULL|| C == NULL || L == NULL)
        return 1;

    for(int f = 0; f < k; f++){
        scanf("%d %d %d", &L[f], &C[f], &A[f]);
 
        if(L[f] > i_max){
            i_max = L[f];
        }
    }
    
    //Ordena os elementos da lista
    qsort(L, k, sizeof(int), comparar_inteiros);

    //Cria o vetor R, e a partir do vetor L ele é preenchido
    int *R = malloc((i_max +1) * sizeof(int));
    realocar_vetorR(R, k, L);


    int i, j;
    while(scanf(" %d %d", &i ,&j) != EOF){
        if(i == -1 && j == -1)
            break;

        int quantidade_deNumeros = procurar_Nnulos(R, i);
        if(quantidade_deNumeros){
            int valor_j = procurar_coluna(R, C, j, i);
                if(valor_j){
                    printf(" %d\n", A[valor_j]);
                }

                else{ //Talvez isso de problema, pois vai que encontra na posição 0, e ele le como False
                    printf("0\n");
                }

        }

        else{
            printf("%d\n", quantidade_deNumeros);
        }

    }


    for(int f = 0; f < k; f++){
        //printf("A na é %d, na posicao %d\n", A[f], f);
        //printf("C na é %d, na posicao %d\n", C[f], f);
        printf("L é igual a %d na posicao %d\n", L[f], f);
    }
    //printf("%d\n", i_max);

    for(int f = 0; f < i_max + 2; f ++){
        printf("R é igual a %d na posicao %d\n", R[f], f);
    }

    free(C);
    free(L);
    free(A);
    free(R);

}
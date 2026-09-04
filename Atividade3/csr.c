#include <stdio.h>
#include <stdlib.h>

int comparar_inteiros(const void *a, const void *b){
    //Compara dois inteiros da lista, para serem ordenados
    return (*(int *)a) - (*(int *)b);
}


void realocar_vetorR(int *R, int k, int *L){
    R[0] = 0; //O vetor R sempre começa zerado

    int posicao = 1;
    int ocorrencia = 1;
    for(int f = 0; f < k; f++){
        if(L[f] == L[f+1] && (L[f]+1) == posicao){
            ocorrencia += 1;
            
        }
        else if(L[f] != L[f+1] && (L[f]+1) == posicao){
            R[posicao] = ocorrencia;
            posicao += 1;
            if(L[f + 1] + 1 == posicao || f + 1 > k){ // Isso da dando erro na memoria eu acho, ele le um numero que não existe no limite da lista e da errado
                ocorrencia += 1;
            }

        }
        else{
            R[posicao] = ocorrencia;
            posicao += 1;
            //atual = L[f];
            f --;
        }
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


    int *R = malloc((i_max +1) * sizeof(int));
    realocar_vetorR(R, k, L);


    
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
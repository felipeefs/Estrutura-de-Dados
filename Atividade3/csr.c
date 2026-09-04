#include <stdio.h>
#include <stdlib.h>

int comparar_inteiros(const void *a, const void *b){
    //Compara dois inteiros da lista, para serem ordenados
    return (*(int *)a) - (*(int *)b);
}

void realocar_vetorR(int *R, int k, int *L){
    R[0] = 0; //O vetor R sempre começa zerado
    
    for(int f = 0; f < k; f++){
        
        
    }


}



int main(){
    int k, i, j, x, i_max = 0;
    scanf(" %d", &k);
    int *A = malloc(k * sizeof(int)); //Armazena os valores de x
    int *C = malloc(k * sizeof(int)); //Armazena os valores das colunas
    int *L = malloc(k * sizeof(int));

    if(A == NULL|| C == NULL || L == NULL)
        return 1;

    for(int f = 0; f < k; f++){
        scanf("%d %d %d", &L[f], &C[f], &A[f]);
 
        if(L[i] > i_max){
            i_max = L[i];
        }
    }
    
    //Ordena os elementos da lista
    qsort(L, k, sizeof(int), comparar_inteiros);


    int *R = malloc((i_max +1) * sizeof(int));
    realocar_vetorR(&R, k, &L);


    /*
    for(int f = 0; f < k; f++){
        printf("A na é %d, na posicao %d\n", A[f], f);
        printf("C na é %d, na posicao %d\n", C[f], f);
        printf("L é igual a %d na posicao %d\n", L[f], f);

        printf("%d\n", i_max);
    }
        */

    free(C);
    free(L);
    free(A);
    

}
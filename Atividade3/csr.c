#include <stdio.h>
#include <stdlib.h>

//Usar malloc ou calloc para criar matrizes e vetores dinamicos


int main(){
    int k, i, j, x, i_max = 0;
    scanf(" %d", &k);
    int *A = malloc(k * sizeof(int));
    int *C = malloc(k * sizeof(int));

    if(A == NULL|| C == NULL)
        return 1;

    for(int f = 0; f < k; f++)
        scanf("%d %d %d", &i, &C[f], &A[f]);

        if(i > i_max){
            i_max = i;
        }


    for(int f = 0; f < k; f++){
        printf("A na é %d, na posicao %d\n", A[f], f);
        printf("C na é %d, na posicao %d\n", C[f], f);

        printf("%d\n", i_max);
    }


}
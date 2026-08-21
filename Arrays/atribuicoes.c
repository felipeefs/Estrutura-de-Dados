#include <stdio.h>

int main(){
    int A[30] = {0, 1, 2, 3, [4 ... 9] = 10, [10] = 100, 101, [20] = 200, [29] = 290 };
    //Ao color [] é possível adicionar um valor em uma posição do vetor, da forma que desejar

    int i;
    for (i = 0; i < 30; i++)
        printf("%d ", A[i]);
}
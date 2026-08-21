#include <stdio.h>

int main(void) {
    int A[5] = { 10, 20, 30, 40, 50 };
    int B[5] = { 10, 20 }; //Como a lista é menor que o vetor, os ultimos elementos serão 0
    int C[5] = { 0 }; //Cria um vetor com 5 elementos iguais a 0
    int D[5] = { 10, 20, 30, 40, 50, 60}; //Elementos que ultrapassam o tamanho do vetor viram 0
    int E[] = { 10, 20, 30, 40, 50 }; //Cria um vetor com o tamanho da lista

    int n = 5;
    //int F[n] = { 0 };  erro

    printf("i\tA\tB\tC\tD\tE\tF\n");
    for (int i=0; i<5; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,A[i],B[i],C[i],D[i],E[i]);

return 0;
}
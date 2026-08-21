#include <stdio.h>
#define m 4
#define n 6

int main(void){

    int A[m][n];
    int i, j;

    for(i= 0; i<m; i++){
        for (j = 0; j<n; j++)
            A[i][j] = i*n + j;
    }

    for (i=0; i<m; i++) {
        for (j=0; j<n; j++)
            printf("%5d ", A[i][j]);

    printf("\n");
    }

    return 0;
}

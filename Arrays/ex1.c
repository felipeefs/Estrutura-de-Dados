#include <stdio.h>

int main(void) {
    double X[12] = {0};
    printf("%f\n", X);
    int x=111, y=222, z=333;
    int A[5];

    for (int i=-5; i<10; i++)
        printf("%d:%d\n", i, A[i]);

    for (int i=-5; i<10; i++)
        A[i] = i;

    printf("\n");

    for (int i=-5; i<10; i++)
        printf("%d:%d\n", i, A[i]);

    printf("\n");
    printf("x %d y %d z %d\n", x, y, z);
    
    return 0;
}
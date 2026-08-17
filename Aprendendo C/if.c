#include <math.h>
#include <stdio.h>

int bhaskara(int a, int b, int c){
    int disc = b * b - 4 * a * c;

    int num_sol = 0;
    if (disc < 0){
        return num_sol;
    }
    else if (disc == 0){
        return num_sol == 1;
    }
    else{
        return num_sol == 2;
    }
}

int main(){
    int b = 2;
    int a = 5;
    int c = 1;
    int num_sol = bhaskara(a, b, c);
    printf("O número de soluções da equação é: %d\n", num_sol);
    return 0;
}
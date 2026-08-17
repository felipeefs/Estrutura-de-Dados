#include <math.h>
#include <stdio.h>

int whi(int a){
    /* Usa-se o Break para sair da função mais interna, e continue para pular para o laço mais interno que é encontrada*/
    while (a >= 0){
        printf("%d\n", a);
        a--;
    }
}

int fo(int i, int e){
    for(i = 0; i < 10; i++){
        printf("%d\n", i);
    }

    for(e = 1; e < 512; e *= 2){
        printf("%d\n", e);
    }
}
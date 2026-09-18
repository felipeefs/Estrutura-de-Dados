#include <stdio.h>

typedef union {
    char c;
    int i;
    double d;
} multiple;

typedef struct {
    char type;
    multiple data;
} item;

int main(void) {
    item V[100];

    // Elemento 0: guarda um Double
    V[0].type = 'D';
    V[0].data.d = 3.14;

    // Elemento 1: guarda um Inteiro
    V[1].type = 'I';
    V[1].data.i = 101;

    // Elemento 2: guarda um Caractere
    V[2].type = 'C';
    V[2].data.c = 'Z';

    // Exibição dos dados do vetor
    for (int k = 0; k < 3; k++) {
        switch (V[k].type) {
            case 'D':
                printf("V[%d] e do tipo Double: %.2f\n", k, V[k].data.d);
                break;
            case 'I':
                printf("V[%d] e do tipo Int: %d\n", k, V[k].data.i);
                break;
            case 'C':
                printf("V[%d] e do tipo Char: %c\n", k, V[k].data.c);
                break;
        }
    }

    return 0;
}
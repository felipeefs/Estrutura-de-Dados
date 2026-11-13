#include <stdio.h>
#include <stdlib.h>

typedef struct tabela{
    int chave;
    long valor;
}tabela;



int main(){
    tabela *T = NULL;
    char operacao;

    while(scanf(" %c", &operacao) == 1){
        switch (operacao){
        case 'c':{
            int n;
            scanf("%d", n);
            if(T != NULL){
                free(T);
            }
            T = malloc(n * sizeof(tabela));
        }
            break;
        
        default:
            break;
        }


    }
}
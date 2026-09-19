#include <stdio.h>
#include <stdlib.h>

struct{
    int elemento;
    struct no *prox;
} typedef no;


void 


int main(){
    no** L= malloc(128 * sizeof(no*)); //Uma lista que terá 128 conjuntos

    for(int i = 0; i< 128; i++){
        L[i] = malloc(sizeof(no));
        L[i] -> prox = NULL;
    }

    char operacao;
    while((scanf(" %c", &operacao) != EOF)){
        if(operacao == 't')
            break;
    
        switch (operacao){
        case 'c':

            break;
        
        default:
            break;
        }

    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAZIO -1
#define REMOVIDO -2

typedef struct tabela{
    int chave;
    long valor;
}tabela;



int h1(int chave, int n){
    return chave % n;
}

int h2(int chave, int n){
    return 1 + (chave % n);
}

tabela *criar_T(int n){
    //Cria uma tabela vazia
    tabela *T = malloc(n * sizeof(tabela));
    for(int i = 0; i<n; i++){
        T[i].chave = VAZIO;
        T[i].valor = VAZIO;
    }
    return T;
}

void inserir_chave(tabela *T, int chave, long valor, int n){
    int pos = h1(chave, n);
    int guarda_chave;
    long guarda_valor;
    int rem = -1;

    for(int i = 0; i< n; i++){
        int ind = (pos + i * h2(chave, n)) % n;
        if(T[ind].chave == chave){ //Chave já existe
            T[ind].chave = chave;
            return;
        }
        else if(T[ind].chave == REMOVIDO){
            if(rem == -1){
                rem = ind; //Guarda o ind da primeira posição removida, para inserir_chave nela depois
            }
        }
        else if(T[ind].chave == VAZIO){ 
            if(rem != -1){
                ind = rem;
            }
            T[ind].chave = chave;
            T[ind].valor = valor;
            return;
        }
        else{ //Achou uma outra chave
            guarda_chave = T[ind].chave;
            guarda_valor = T[ind].valor;
            T[ind].chave = chave;
            T[ind].valor = valor;
            inserir_chave(T, guarda_chave, guarda_valor, n);
            return;
        }
    }
    if(rem != -1){ //Quando há uma possivel removida e não teve proximas posições vazias
        T[rem].chave = chave;
        T[rem].valor = valor;
    }
    return;
}

void remover_chave(tabela *T, int chave, int n){
    int pos = h1(chave, n);

    for(int i = 0; i < n; i++){
        int ind = (pos + i * h2(chave, n)) % n;
        if(T[ind].chave == chave){
            T[ind].chave = REMOVIDO;
            T[ind].valor = REMOVIDO;
            return;
        }
    }
    return;
}

int buscar_chave(tabela *T, int chave, int n){
    int pos = h1(chave, n);

    for(int i = 0; i < n; i++){
        int ind = (pos + i * h2(chave, n)) % n;
        if(T[ind].chave == chave)
            return ind;
        else if(T[ind].chave == VAZIO)
            return -1; //Retorna -1 se não achou a chave
    }
    return -1;
}

int main(){
    tabela *T = NULL;
    char operacao;
    int n;
    while(scanf(" %c", &operacao) == 1){

        if(operacao == 'f'){
            break;
        }

        switch (operacao){
        case 'c':{
            scanf("%d", &n);
            if(T != NULL){
                free(T);
            }
            T = criar_T(n);            
        }
            break;
        
        case 'i':{
            int chave;
            long valor;
            scanf("%d %ld", &chave, &valor);
            inserir_chave(T, chave, valor, n);
        }
            break;
        
        case 'r':{
            int chave;
            scanf("%d", &chave);
            remover_chave(T, chave, n);
        }
            break;

        case 'b':{
            int chave;
            scanf("%d", &chave);
            if(buscar_chave(T, chave, n) != -1){
                int ind = buscar_chave(T, chave, n);
                printf("%d -> %ld\n", T[ind].chave, T[ind].valor);
            }
            else{
                printf("%d -> !E\n", chave);
            }
        }
            break;

        default:
            break;
        }


    }
}
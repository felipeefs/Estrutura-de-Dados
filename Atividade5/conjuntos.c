#include <stdio.h>
#include <stdlib.h>

struct no{
    int elemento;
    struct no *prox;
};

typedef struct no no;


void criar_conjunto(){
    //Por enquanto não faz nada, porque todos os itens da lista já estão criados, porém ele deve verificar se um conjunto já existe na posição da lista, e apaga-lo caso já exista

}

void inserir_elementos(no **L, int j, int t){    
    no *p = L[j];
    long c = 0;

    while(c<t){
        int numero;
        scanf(" %d", &numero);
        no* novo = malloc(sizeof(no));
        novo->elemento = numero;

        //Adiciona todos os novos elementos no começo da lista, após o nó sentinela
        

        novo->prox = p->prox;
        p->prox = novo;
    


        c++;
    }
}


void imprimir_crescente(no **L, int i){
    L[i] = L[i]->prox;

    while(L[i] != NULL){
        printf("%d", L[i] -> elemento);
        L[i] = L[i] -> prox;
    }


}

int main(){
    no** L= malloc(128 * sizeof(no*)); //Uma lista que terá 128 conjuntos

    //Para cada item da lista, recebe uma lista encadeada
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
            criar_conjunto();
            break;
        case 'i':
            int j, t;
            scanf(" %d %d", &j, &t);
            inserir_elementos(L, j, t);
            break;

        case 'p':
            int i;
            scanf(" %d", &i);

            break;
        
        default:
            break;
        }

    }
}
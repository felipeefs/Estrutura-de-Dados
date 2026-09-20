#include <stdio.h>
#include <stdlib.h>

struct no{
    int elemento;
    struct no *prox;
};

typedef struct no no;

void criar_conjunto(no **L, int k){
    //Por enquanto não faz nada, porque todos os itens da lista já estão criados, porém ele deve verificar se um conjunto já existe na posição da lista, e apaga-lo caso já exista
    if(L[k] != malloc(sizeof(no))){
        L[k] = malloc(sizeof(no));
        L[k] -> prox = NULL;
    }
    else
        free(L[k]);
}

void inserir_elementos(no **L, int j, int t){    
    //Insere elementos de forma crescente na lista encadeada de indice j

    long c = 0;
    while(c<t){
        no *p = L[j];
        
        int numero;
        scanf(" %d", &numero);
        no* novo = malloc(sizeof(no));
        novo->elemento = numero;

        //Adiciona todos os elementos em ordem crescente
        if(p->prox == NULL || numero < p->prox->elemento){ //Adiciona o elemento na primeira posição caso ele seja menor ou o próximo seja um NULL
            novo->prox = p->prox;
            p->prox = novo;
        }

        else if(numero > p->prox->elemento){ //Adiciona os próximos, maiores elementos
            while (p->prox != NULL && numero > p->prox->elemento){
                p = p->prox;
            }
            novo->prox = p->prox;
            p->prox = novo;
        }
        c++;
    }
}

void imprimir_crescente(no **L, int i){
    L[i] = L[i]->prox;

    printf("{");
    while(L[i] != NULL){
        if(L[i] -> prox == NULL){
            printf("%d", L[i] -> elemento);
            break;
        }
        printf("%d, ", L[i] -> elemento);
        L[i] = L[i] -> prox;
    }
    printf("}");
}

int main(){
    no** L= malloc(128 * sizeof(no*)); //Uma lista que terá 128 conjuntos

    //Para cada item da lista, recebe uma lista encadeada
    /*
    for(int i = 0; i< 128; i++){
        L[i] = malloc(sizeof(no));
        L[i] -> prox = NULL;
    }
    */
   
    char operacao;
    while((scanf(" %c", &operacao) != EOF)){
        if(operacao == 't')
            break;
    
        switch (operacao){
        case 'c':
            int k;
            scanf(" %d", &k);
            criar_conjunto(L, k);
            break;

        case 'i':
            int j, t;
            scanf(" %d %d", &j, &t);
            inserir_elementos(L, j, t);
            break;

        case 'p':
            int i;
            scanf(" %d", &i);
            imprimir_crescente(L, i);
            break;
        
        default:
            break;
        }

    }
}
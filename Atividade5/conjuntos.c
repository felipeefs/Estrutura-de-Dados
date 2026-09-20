#include <stdio.h>
#include <stdlib.h>

struct no{
    int elemento;
    struct no *prox;
};

typedef struct no no;

void criar_conjunto(no **L, int i){
    //Por enquanto não faz nada, porque todos os itens da lista já estão criados, porém ele deve verificar se um conjunto já existe na posição da lista, e apaga-lo caso já exista
    if(L[i] != malloc(sizeof(no))){
        L[i] = malloc(sizeof(no));
        L[i] -> prox = NULL;
    }
    else
        free(L[i]);
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

void remover_elementos(no **L, int j, int t){

    int c =0;
    while (c < t){
        int numero;
        scanf(" %d", &numero);

        no *p = L[j];

        while(p->prox != NULL){
            if(numero == p->prox->elemento){
                no* guardo = p -> prox;
                p->prox = p->prox->prox;
                free(guardo);
                break;
            }
            p = p-> prox;
        }
        c ++;
    }
}

void imprimir_crescente(no **L, int i){

    no *p = L[i]; //Apontador p apontando para o mesmo lugar que o sentinela
    p = p->prox;

    printf("{");
    while(p != NULL){
        if(p -> prox == NULL){
            printf("%d", p -> elemento);
            break;
        }
        printf("%d, ", p -> elemento);
        p = p -> prox; //Ele passa para frente, mas depois precisa voltar para o que era antes
    }
    
    printf("}");
}

void imprimir_unico(no **L, int i, int x){
    no *p = L[i];
    p = p->prox;

    int booleano = 1; 
    while(p->prox != NULL){
        if(x == p->prox->elemento){
            printf("%d esta em C%d\n", x, i);
            booleano = 0;
            break;
        }
        p = p->prox;
    }
    if(booleano)
        printf("%d nao esta em C%d", x, i);

}

int main(){
    no** L= malloc(128 * sizeof(no*)); //Uma lista que terá 128 conjuntos
   
    char operacao;
    while((scanf(" %c", &operacao) != EOF)){
        if(operacao == 't')
            break;
    
        switch (operacao){
        case 'c':{
            int i;
            scanf(" %d", &i);
            criar_conjunto(L, i);
            break;
        }

        case 'i':{
            int j, t;
            scanf(" %d %d", &j, &t);
            inserir_elementos(L, j, t);
            break;
        }

        case 'p':{
            int i;
            scanf(" %d", &i);
            imprimir_crescente(L, i);
            break;
        }

        case 'r':{
            int j, t;
            scanf(" %d %d", &j, &t);
            remover_elementos(L, j, t);
            break;
        }
        
        case 'e':{
            int i, x;
            scanf(" %d %d", &i, &x);
            imprimir_unico(L, i, x);
            break;
        }

        default:
            break;
        }

    }
}
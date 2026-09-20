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

void unir_conjuntos(no **L, int i, int j, int k){
    no *p_j = L[j];
    p_j = p_j->prox;

    no* p_i = L[i];
    //Loop para copiar todos os elementos de L[j] em L[i]
    while(p_j != NULL){
        no *novo = malloc(sizeof(no));
        novo->elemento = p_j->elemento;
        
        novo->prox = p_i -> prox;
        p_i -> prox = novo;

        p_i = p_i -> prox;
        p_j = p_j -> prox;
    }

    //Loop para adicionar todos os elementos de L[k] que ainda não estão em L[i]
    no *p_k = L[k];
    p_k = p_k -> prox;

    p_i = L[i];
    while(p_k != NULL){

        while(p_i->prox != NULL && p_i->prox->elemento < p_k->elemento){
             p_i = p_i->prox;
        }

        if(p_i->prox == NULL || p_i->prox->elemento != p_k->elemento){
            no *novo = malloc(sizeof(no));
            novo->elemento = p_k ->elemento;
                
            novo->prox = p_i -> prox;
            p_i -> prox = novo;
        }
        p_k = p_k -> prox;
        p_i = L[i];
    }
}

void intersectar_conjuntos(no **L, int i, int j, int k){
    no *p_j = L[j];
    no *p_k = L[k];
    no* p_i = L[i];

    p_j = p_j->prox;
    while (p_j != NULL){

        p_k = L[k];
        p_k = p_k -> prox;

        while(p_k !=NULL){
            if(p_j->elemento == p_k->elemento){
                no *novo = malloc(sizeof(no));
                novo->elemento = p_j -> elemento;

                novo->prox = p_i -> prox;
                p_i -> prox = novo;

                p_i = p_i -> prox; //p_i avança para ficar na ordem crescente 

                break;
            }
            p_k = p_k -> prox;
        }
        p_j = p_j -> prox;
    }
}

void diferenciar_conjuntos(no **L, int i, int j, int k){
    no *p_j = L[j];
    no *p_k = L[k];
    no* p_i = L[i];
    
    p_j = p_j->prox;
    while (p_j != NULL){
        int booleano = 0;

        p_k = L[k];
        p_k = p_k -> prox;

        while(p_k !=NULL){
            if(p_j->elemento == p_k->elemento){
                booleano = 0;
                break;
            }
            booleano = 1;
            p_k = p_k -> prox;
        }

        if(booleano){
            no *novo = malloc(sizeof(no));
            novo->elemento = p_j -> elemento;

            novo->prox = p_i -> prox;
            p_i -> prox = novo;

            p_i = p_i -> prox; //p_i avança para ficar na ordem crescente 


        }
        p_j = p_j -> prox;
    }


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

        case 'u':{
            int i, j, k;
            scanf(" %d %d %d", &i, &j, &k);
            criar_conjunto(L, i);
            unir_conjuntos(L, i, j, k);
            break;
        }

        case 'n':{
            int i, j, k;
            scanf(" %d %d %d", &i, &j, &k);
            criar_conjunto(L, i);
            intersectar_conjuntos(L, i, j, k);
            break;
        }

        case 'm':{
            int i, j, k;
            scanf(" %d %d %d", &i, &j, &k);
            criar_conjunto(L, i);
            diferenciar_conjuntos(L, i, j, k);
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
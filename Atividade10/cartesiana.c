#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    long data;
    long index;
    struct no* right;
    struct no* left;
}no;


no *change_root(no *tree, long x, long index){
    //Cria um novo nó, que se torna a raiz (por ser o menor número) e toda a subárvore antiga ficam a sua esquerda
    no *novo = malloc(sizeof(no));
    novo->data = x;
    novo->index = index;
    novo->right = NULL;
    novo->left = tree;

    return novo;
}

void insert_middle(no *tree, long x, long index){
    //Caso o valor da lista esteja entre valores da árvore, ele é inserido no meio deles
    no *novo = malloc(sizeof(no));
    novo->data = x;
    novo->index = index;

    novo->left = tree -> right;
    tree->right = novo;
    novo->right = NULL;
}

void insert_end(no *tree, long x, long index){
    //Caso o valor seja maior que todos, ele é inserido no final
    no *novo = malloc(sizeof(no));
    novo->data = x;
    novo->index = index;

    tree->right = novo;
    novo->right = NULL;
    novo->left = NULL;
}



int main(){
    long n;
    
    while(scanf(" %ld", &n) != 0){
        long* A = calloc(n, sizeof(long));

        for(long i = 0; i < n; i++){
            long value;
            scanf(" %ld", &value);
            A[i] = value;
        }
    
    //Adiciona o primeiro elemento da árvore
    no *tree = malloc(sizeof(no));
    tree->data = A[0];
    tree->index = 0;
    tree->right = NULL; 
    tree->left = NULL;

    for(int i= 1; i< n; i++){
        no *p = tree;

        if(A[i] < p->data){
            //Se o item for menor que o primeiro da árvore ele vira a nova raiz
            tree = change_root(tree, A[i], i);
        }

        else{
            //printf("%ld ", p->data);
            int booleano = 1;
            while(p->right != NULL){
                if(A[i] > p->data && A[i] < p->right->data){
                    insert_middle(p, A[i], i);
                    booleano = 0;
                    break;
                }
                p = p->right;
            }
            if(booleano)
                insert_end(p, A[i], i);
            p = tree;
        }

    }
    while(tree->left != NULL){
        printf(" %ld", tree->data);
        tree = tree->left;

    }


    


    }
}


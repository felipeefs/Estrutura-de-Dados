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

no *insert_middle(no *tree, long x, long index){
    //Caso o valor da lista esteja entre valores da árvore, ele é inserido no meio deles
    no *novo = malloc(sizeof(no));
    novo->data = x;
    novo->index = index;

    novo->left = tree -> right;
    tree->right = novo;
    novo->right = NULL;

    return novo;
}

no *insert_end(no *tree, long x, long index){
    //Caso o valor seja maior que todos, ele é inserido no final
    no *novo = malloc(sizeof(no));
    novo->data = x;
    novo->index = index;

    tree->right = novo;
    novo->right = NULL;
    novo->left = NULL;

    return novo;
}


void printf_porLargura(no *tree, long n){
    //Printa a árvore criada por largura
    no **fila = malloc(n * sizeof(no*)); 
    long first = 0;
    long end = 0;

    fila[end++] = tree;
    
    while(first < end){
        long nos_no_nivel = end - first;

        for(long i = 0; i< nos_no_nivel; i++){
            no *p = fila[first++];

            printf("%ld ", p->index);

            if(p->left != NULL)
                fila[end++] = p->left;
            if(p->right != NULL)
                fila[end++] = p->right;
        }
        printf("\n");

    }
    printf("\n");
    for(long i = 0; i< end; i++)
        free(fila[i]);
}



int main(){
    long n;
    
    while(scanf(" %ld", &n) == 1 && n!= 0){
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

        no **pilha = malloc(n * sizeof(no*));
        long k = 0; //Adiciona o primeiro no na pilha
        pilha[k++] = tree;

        for(long i= 1; i< n; i++){
            long k_antes = k;
            no* novo;

            while(k > 0 && pilha[k-1]->data >A[i])
                k--;

            if(k == 0){
                //Todos eram maiores: vira a nova raiz
                tree = change_root(tree, A[i], i);
                novo = tree;
            }
            else if(k == k_antes){
                //Nada removido: é maior ou igual a todos, vai no final
                novo = insert_end(pilha[k-1], A[i], i);
            }
            else{
                //Entre pilha[k-1] e o nó que foi removido
                novo = insert_middle(pilha[k-1], A[i], i);
            }

            pilha[k++] = novo;
        }

        printf_porLargura(tree, n);

        free(pilha);
        free(A);
}
}


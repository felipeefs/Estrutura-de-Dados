#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    long fb;
    long id;
    char *vis;
    char *est;
    struct no *left;
    struct no *right;
    struct no *parent;
}no;

void rotacao_direita(no *x){
    //Faz uma rotação para a direita da sub-árvore
    no *y = x->left;
    x->left = y->right;

    if(y->right != NULL)
        y->right->parent = x;

    y->parent = x->parent;

    if(x->parent != NULL){
        if(x->parent->left == x)
            x->parent->left = y;
        else 
            x->parent->right = y;
    }

    y->right = x;
    x->parent = y;
}

void rotacao_esquerda(no *x){
    //Faz uma rotação a direita da sub-árvore
    no *y = x->right;
    x->right = y->left;

    if(y->left != NULL)
        y->left->parent = x;
    
    y->parent = x->parent;

    if(x->parent != NULL){
        if(x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }

    y->left;
    x->parent = y;
}


void balancear_AVL(){



}


void atualizar_fb(no *novo){
    //A partir do nó inserido, sobe toda a sub-árvore atualizando os fatores "fb"
    no *filho = novo;
    no *p = novo->parent;

    while(p != NULL || p->fb != 0){
        if(filho == p->left){ //Se foi inserido na esquerda soma
            p->fb ++;
        //     if(p->fb == 2 || p->fb == -2)
        //         balancear_AVL()
        }
        else{ //Se foi inserido na direita subtrai
            p->fb --;
        //     if(p->fb == 2 || p->fb == -2)
        //         balancear_AVL()
        }

        filho = p;
        p = p->parent;
    }
}

no *inserir(no *tree, long x ,char *vis, char *est){
    if(tree == NULL){ //Se é igual a NULL se torna a raiz
        no *novo = malloc(sizeof(no));
        novo->fb = 0;
        novo->id = x;
        novo->vis = vis;
        novo->est = est;
        novo->parent = NULL;
        novo->left = NULL;
        novo->right = NULL;

        return novo;
    }

    if(x < tree->id){
        tree->left = inserir(tree->left, x, vis, est);
        atualizar_fb(tree->left);
    }
    else if(x > tree->id){
        tree->right = inserir(tree->right, x, vis, est);
        atualizar_fb(tree->right);
    }
    
    return tree;

}

int main(){
    char operador;

    //Criação da árvore
    no *tree = NULL;

    while (scanf(" %c", &operador) != EOF)
    {
        switch (operador){
        case 'i':
            long x;
            char *vis = malloc(100 * sizeof(char));
            char *est = malloc(100 * sizeof(char));
            scanf("%ld %s %s",&x, vis, est);
            tree = inserir(tree, x, vis, est);
            break;
        
        default:
            break;
        }
        
        
    }
    


}
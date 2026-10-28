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
    //Faz uma rotação a esquerda da sub-árvore
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

    y->left = x;
    x->parent = y;
}


void balancear_AVL(no *x, long fb){
    //Analise se precisa de balanceamento na direita ou esquerda, e seu devido caso, e balanceia a árvore
    if(fb == 2){
        no *filho = x->left;
        if(filho->fb >= 0){
            //Caso LL
            rotacao_direita(x);
        }
        else{
            //Caso LR
            rotacao_esquerda(x->left);
            rotacao_direita(x);
        }
    }

    else if(fb == -2){
        no *filho = x->right;
        if(filho->fb <= 0){
            //Faz rotação RR
            rotacao_esquerda(x);
        }
        else{
            //Caso RL
            rotacao_direita(x->right);
            rotacao_esquerda(x);
        }
    }

}


void atualizar_fb(no *novo){
    //A partir do nó inserido, sobe toda a sub-árvore atualizando os fatores "fb"
    no *filho = novo;
    no *p = novo->parent;

    while(p != NULL){
        if(filho == p->left){ //Se foi inserido na esquerda soma
            p->fb ++;
            if(p->fb == 0)
                break;
            else if(p->fb == 2 || p->fb == -2){
                balancear_AVL(p, p->fb);
                break;
            }
        }
        else{ //Se foi inserido na direita subtrai
            p->fb --;
            if(p->fb == 0)
                break;
            else if(p->fb == 2 || p->fb == -2){
                balancear_AVL(p, p->fb);
                break;
        }
    }

        filho = p;
        p = p->parent;
    }
}

no *inserir(no *tree, long x ,char *vis, char *est){
    if(tree == NULL){ //Se é igual a NULL se torna a raiz
        no *novo = malloc(sizeof(no));

        if(novo == NULL)
            return NULL;

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

        if(tree->left != NULL)
            tree->left->parent = tree; //Faz a conexão do novo nó com um pai
    }
    else if(x > tree->id){
        tree->right = inserir(tree->right, x, vis, est);

        if(tree->right != NULL)
            tree->right->parent = tree;
    }
    
    return tree;

}

int main(){
    char operador;

    //Criação da árvore
    no *tree = NULL;

    while (scanf("%c", &operador) != EOF)
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
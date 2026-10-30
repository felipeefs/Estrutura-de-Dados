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

no *rotacao_direita(no *x){
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

    return y;
}

no *rotacao_esquerda(no *x){
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

    return y; //Retorna a nova raiz
}


no *balancear_AVL(no *x, long fb){
    //Analise se precisa de balanceamento na direita ou esquerda, e seu devido caso, e balanceia a árvore
    if(fb == 2){
        no *filho = x->left;
        if(filho->fb >= 0){
            //Caso LL
            x = rotacao_direita(x);

            x->fb = 0; //Depois da rotação, atualiza os valores de fb
            x->right->fb = 0;
        }
        else{
            //Caso LR
            long fb_z = x->left->right->fb; //Guaurda o fb da futura nova raiz
            x->left = rotacao_esquerda(x->left);
            x = rotacao_direita(x);

            if(fb_z == 0){
                x->fb = 0;
                x->right->fb = 0;
                x->left->fb = 0;
            }
            else if(fb_z == 1){
                x->fb = 0;
                x->right->fb = 0;
                x->left->fb = -1;
            }
            else if(fb_z == -1){
                x->fb = 0;
                x->left->fb = 1;
                x->right->fb = 0;
            }

        }
    }

    else if(fb == -2){
        no *filho = x->right;
        if(filho->fb <= 0){
            //Faz rotação RR
            x = rotacao_esquerda(x);

            x->fb = 0; //Depois da rotação, atualiza os valores de fb
            x->left->fb = 0;
        }
        else{
            //Caso RL
            long fb_z = x->right->left->fb; //Guaurda o fb da futura nova raiz
            x->right = rotacao_direita(x->right);
            x = rotacao_esquerda(x);

            if(fb_z == 0){
                x->fb = 0;
                x->right->fb = 0;
                x->left->fb = 0;
            }
            else if(fb_z == 1){
                x->fb = 0;
                x->right->fb = -1;
                x->left->fb = 0;
            }
            else if(fb_z == -1){
                x->fb = 0;
                x->right->fb = 0;
                x->left->fb = 1;
            }
            
        }
    }

    return x;
}

void atualizar_fb(no *novo, no **tree){
    //A partir do nó inserido, sobe toda a sub-árvore atualizando os fatores "fb"
    no *filho = novo;
    no *p = novo->parent;

    while(p != NULL){
        if(filho == p->left){ //Se foi inserido na esquerda soma
            p->fb ++;
            if(p->fb == 0)
                break;
            else if(p->fb == 2 || p->fb == -2){
                no *nova_raiz = balancear_AVL(p, p->fb); //Atualiza a nova raiz
                if(nova_raiz->parent == NULL)
                    *tree = nova_raiz;

                break;
            }
        }
        else{ //Se foi inserido na direita subtrai
            p->fb --;
            if(p->fb == 0)
                break;
            else if(p->fb == 2 || p->fb == -2){ 
                no *nova_raiz  = balancear_AVL(p, p->fb); //Atuliza a nova raiz
                if(nova_raiz->parent == NULL)
                    *tree = nova_raiz;

                break;
        }
    }
        filho = p;
        p = p->parent;
    }
}

no *inserir(no *tree, long x ,char *vis, char *est, no **inserido){
    //A partir de uma recursão, percorre toda a árvore de busca, indo para a direita quando o valor x for maior, e para a esquerda quando x for menor; para inseri-lo no final de uma sub-árvore
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

        *inserido = novo;
        return novo;
    }

    if(x < tree->id){
        tree->left = inserir(tree->left, x, vis, est, inserido);

        if(tree->left != NULL)
            tree->left->parent = tree; //Faz a conexão do novo nó com um pai
    }
    else if(x > tree->id){
        tree->right = inserir(tree->right, x, vis, est, inserido);

        if(tree->right != NULL)
            tree->right->parent = tree;
    }
    
    return tree;

}

void atualizar(no *tree, long x ,char *vis, char *est){
    //Procura, a partir de uma pesquisa em árvore de buscas, um nó com id == x para atualizar a visibilidade e o estado
    if(tree == NULL)
        return;

    if(tree->id == x){
        tree->vis = vis;
        tree->est = est;
        return;
    }
    else if(x > tree->id)
        atualizar(tree->right, x, vis, est);
    else    
        atualizar(tree->left, x, vis, est);
}

no *buscar(no *tree, long x){
    //Busca um nó x especifico
    if(tree == NULL){
        return NULL;
    }

    if(x == tree->id)
        return tree;
        
    else if(x > tree->id){
        return buscar(tree->right, x);
    }
    else if(x < tree->id){
        return buscar(tree->left, x);
    }
}

void printar_crescente(no *tree){
    //Utiliza-se um algoritmo de busca em-ordem para printar toda a árvore em ordem crescente
    if(tree == NULL)
        return;

    printar_crescente(tree->left);
    printf(" %ld", tree->id);
    printar_crescente(tree->right);
}

int main(){
    char operador;

    //Criação da árvore
    no *tree = NULL;

    while (scanf(" %c", &operador) != EOF)
    {
        switch (operador){
        case 'i':{
            long x;
            char *vis = malloc(100 * sizeof(char));
            char *est = malloc(100 * sizeof(char));
            scanf("%ld %20s %20s",&x, vis, est);
            
            no* novo = NULL;
            tree = inserir(tree, x, vis, est, &novo);

            if(novo!= NULL)
                atualizar_fb(novo, &tree);
            else{
                free(vis);
                free(est);
            }
        }
        break;

        case 'a':{
            long x;
            char *vis = malloc(100 * sizeof(char));
            char *est = malloc(100 * sizeof(char));
            scanf("%ld %20s %20s",&x, vis, est);
            
            atualizar(tree, x, vis, est);
        }

            break;

        case 'b':{
            long x;
            scanf("%ld", &x);

            no *buscado = buscar(tree, x);
            if(buscado == NULL){
                printf("%ld nao existe\n", x);
            }
            else
                printf("%ld, %s, %s", x, buscado->vis, buscado->est);
        }
            break;

        case 'l':{
            printf("documentos:");
            printar_crescente(tree);
            printf("\n");
        }
        break;
        
        case 't':
            if(tree == NULL){
                printf("Arvore vazia\n");
                break;
            }

            printf("%ld (raiz) - fb: %ld. visibilidade: %s. estado:%s\n", tree->id, tree->fb, tree->vis, tree->est);

            if(tree->right != NULL)
                printf("%ld (filho dir) - fb: %ld. visibilidade:%s. estado:%s\n", tree->right->id, tree->right->fb, tree->right->vis, tree->right->est);
            else
                printf("Filho dir: NULL\n");

            if(tree->left != NULL)
                printf("%ld (filho esq) - fb: %ld. visibilidade:%s. estado:%s\n", tree->left->id, tree->left->fb, tree->left->vis, tree->left->est);
            else
                printf("Filho esq: NULL\n");

            break;
        
        
        default:
            break;
        }
    }
    
}
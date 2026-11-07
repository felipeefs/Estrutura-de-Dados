#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int t;
    int n; //Posições ocupadas de chave
    int folha; //Indica se é folha
    int *chaves;
    long *ini;
    long *fim;
    struct no **filhos;    
}no;

no *buscar(no *tree, int x, int *pos){
    //Busca uma chave x, se achar devolve 1, se não devolve 0
    int i = 0;
    while(i < tree->n && x > tree->chaves[i]){
        i++;
    }

    if(i<tree->n && x == tree->chaves[i]){
        *pos = x;
        return tree;
    }
    
    if(tree->folha)
        return NULL;
    
    return buscar(tree->filhos[i], x, pos);
}

no *criar_no(int t, int folha){
    no *novo = malloc(sizeof(no));
    if(novo == NULL)
        return NULL;

    novo->t = t;
    novo->n = 0;
    novo->folha= folha; //1 para folha e 0 para não folha 
    novo->chaves = malloc((2*t-1) *sizeof(int));
    novo->ini = malloc((2*t-1) *sizeof(long));
    novo->fim = malloc((2*t-1) *sizeof(long));
    novo->filhos = malloc((2*t) * sizeof(no*));

    if(novo->chaves == NULL || novo->ini == NULL || novo->fim == NULL || novo->filhos == NULL){
        free(novo->chaves);
        free(novo->ini);
        free(novo->fim);
        free(novo->filhos);
        free(novo);
        return NULL;
    }

    for(int i = 0; i < 2*t; i++)
        novo->filhos[i] = NULL;

    return novo;
}

void dividir_filho(no *pai, int i){
    int t = pai->t;

    no *y = pai->filhos[i];
    no *z = criar_no(t, y->folha);

    z->n = t-1;

    // Copia as maiores chaves para z
    for(int j = 0; j < t-1; j++){
        z->chaves[j] = y->chaves[j+t];
        z->ini[j] = y->ini[j+t];
        z->fim[j] = y->fim[j+t];
    }

    // Copia os filhos, caso não seja folha
    if(!y->folha){
        for(int j = 0; j < t; j++)
            z->filhos[j] = y->filhos[j+t];
    }

    // O nó original fica com as menores chaves
    y->n = t-1;

    // Abre espaço para o novo filho
    for(int j = pai->n; j >= i+1; j--)
        pai->filhos[j+1] = pai->filhos[j];

    pai->filhos[i+1] = z;

    // Abre espaço para a chave que vai subir
    for(int j = pai->n-1; j >= i; j--){
        pai->chaves[j+1] = pai->chaves[j];
        pai->ini[j+1] = pai->ini[j];
        pai->fim[j+1] = pai->fim[j];
    }

    // Promove a chave central
    pai->chaves[i] = y->chaves[t-1];
    pai->ini[i] = y->ini[t-1];
    pai->fim[i] = y->fim[t-1];

    pai->n++;
}

void inserir_nao_cheio(no *x, int k, long ini, long fim){
    //insere no quando no não está cheio
    int i = x->n-1;

    if(x->folha){
        // Abre espaço para a nova chave
        while(i >= 0 && k < x->chaves[i]){
            x->chaves[i+1] = x->chaves[i];
            x->ini[i+1] = x->ini[i];
            x->fim[i+1] = x->fim[i];
            i--;
        }

        // Insere a chave e suas posições
        x->chaves[i+1] = k;
        x->ini[i+1] = ini;
        x->fim[i+1] = fim;

        x->n++;
    }

    else{

        // Descobre qual filho deve receber a chave
        while(i >= 0 && k < x->chaves[i])
            i--;

        i++;

        // Se o filho estiver cheio, divide
        if(x->filhos[i]->n == 2*x->t-1){

            dividir_filho(x, i);

            if(k > x->chaves[i])
                i++;
        }
        inserir_nao_cheio(x->filhos[i], k, ini, fim);
    }
}


void inserir(int x, long ini, long fim, no **tree, int t){
    // Verifica se a chave já existe
    int pos;
    if(*tree != NULL && buscar(*tree, x, &pos) != NULL)
        return;

    // Se a árvore estiver vazia
    if(*tree == NULL){
        *tree = criar_no(t, 1);
        if(*tree == NULL)
            return;
    }

    no *r = *tree;

    // Verifica se a raiz está cheia
    if(r->n == 2*t-1){

        // Cria uma nova raiz
        no *s = criar_no(t, 0);
        if(s == NULL)
            return;

        s->filhos[0] = r;

        // Atualiza a raiz
        *tree = s;

        // Divide a raiz antiga
        dividir_filho(s, 0);

        int i = 0;

        if(x > s->chaves[0])
            i++;

        inserir_nao_cheio(s->filhos[i], x, ini, fim);
    }

    else{
        inserir_nao_cheio(r, x, ini, fim);
    }
}

void limpar_arvore(no *tree){
    //Libera toda a arvore já existente 
    if(tree == NULL)
        return;
    
    if(!tree->folha){ //Percorre todos os filhos caso não for uma folha
        for(int i = 0; i <= tree->n; i++){
            limpar_arvore(tree->filhos[i]);
        }
    }
    free(tree->chaves);
    free(tree->filhos);
    free(tree->fim);
    free(tree->ini);
    free(tree);
}

int main(){
    char operacao;
    no *tree = NULL;
    int t;
    while (scanf(" %c", &operacao) == 1)
    {
        switch(operacao){
            case 'c':{
                scanf("%d", &t);
                if(tree!=NULL){
                    limpar_arvore(tree);
                }
                tree = NULL;
            }
            break;

            case 'i':{
                int x;
                long ini, fim;
                scanf("%d %ld %ld", &x, &ini, &fim);
                inserir(x, ini, fim, &tree, t);
            }
            break;

            case 'b':{
                int x;
                scanf("%d", &x);
                int pos;
                no *achado = buscar(tree, x, &pos);
                if(achado!=NULL){
                    printf("%d: %ld %ld", x, achado->ini[pos], achado->fim[pos]);
                }
            }
            break;
        }
    }
    


}
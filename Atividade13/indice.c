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

no *criar_arvore(int t){
    no *novo = malloc(sizeof(no));
    if(novo == NULL)
        return NULL;

    novo->t = t;
    novo->n = 0;
    novo->folha=0; //1 para folha e 0 para não folha 
    novo->chaves = malloc((2*t-1) *sizeof(int));
    novo->ini = malloc((2*t-1) *sizeof(int));
    novo->fim = malloc((2*t-1) *sizeof(int));
    novo->filhos = malloc((2*t) * sizeof(no*));

    return novo;
}

no *inserir(int x, long ini, long fim, no *tree){
    if(tree == NULL){
        

    }

}

int main(){
    char operacao;
    while (scanf(" %c", &operacao) == 1)
    {
        switch(operacao){
            case 'c':{
                int t;
                scanf("%d", &t);
                no *tree = criar_arvore(t);
            }
            break;

            case 'i':{
                int x;
                long ini, fim;
                scanf("%d %ld %ld", &x, &ini, &fim);
                
            }   
            break;


        }
    }
    


}
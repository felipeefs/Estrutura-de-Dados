#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct no{
    char *word;
    long freq;
    struct no *left;
    struct no *right;

}no;

no *insert(char *w, long f, no *tree){
    no *novo = malloc(sizeof(no));
    novo->freq = f;
    novo->word = w;
    novo->left = NULL;
    novo->right = NULL;

    no *u = tree; //Variável para avançar a árvore no loop
    no *p = NULL;
    while(u != NULL){
        p = u;
        if(novo->word == p->word){
            long freq = novo->freq;    
            p->freq = freq;
            goto fim;
        }
        else if(novo->freq < u->freq)
            u = u->left;
        else 
            u = u->right;
    }

    if(p == NULL){
        //Se o p é nulo significa que vamos adicionar o primeiro item na árvore
        tree = novo; 
    }
    else if(novo->freq < p->freq)
        p->left = novo;
    else 
        p->right = novo;

    fim:
    return tree;
}

int search_inOrder(char *w, no *tree){
    no *p = tree;
    if(p != NULL){
        if(strcmp(p->word, w) == 0){
            printf("%s %ld\n", p->word, p->freq);
            return 1;
        }
        search_inOrder(w, p->left);
        search_inOrder(w, p->right);
    }
    // printf("%s not found.\n", w);
    // return 0;
}


int main(){
    char comando[20];
    no *tree = NULL;

    while(scanf(" %19s", comando) != EOF){
        if(strcmp(comando, "EXIT") == 0)
            break;

        else if(strcmp(comando, "INSERT") == 0){
            char *w = malloc(1000 * sizeof(char));
            long f;
            scanf("%999s %ld", w, &f);
            tree = insert(w, f, tree);
        }
        else if(strcmp(comando, "SEARCH") == 0){
            char *w = malloc(1000 * sizeof(char));
            scanf("%999s", w);
            if(!search_inOrder(w, tree)){
                printf("%s not found.\n", w);
            }

        }   

    }

    while (tree != NULL)
    {
        printf("%ld\n", tree->freq);
        tree = tree ->left;
    }
    


}
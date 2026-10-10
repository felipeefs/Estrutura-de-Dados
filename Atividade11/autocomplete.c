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
    //Percorre a árvore comparando o valor da palavra com cada nó, até chegar ao final de um ramo para ser inserida
    if(tree == NULL){
        no *novo = malloc(sizeof(no));
        novo->freq = f;
        novo->word = w;
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    }

    int c = strcmp(w, tree->word);
    if(c == 0) //Mesma palavra
        tree->freq = f;
    else if(c < 0) //Palavra w menor, então percorre a esquerda
        tree->left = insert(w, f, tree->left);
    else  //Palavra w maior, então percorre a direita
        tree->right = insert(w, f, tree->right);
    
    return tree;
}

int search_inOrder(char *w, no *tree){
    //Procura uma palavra com base no seu "w", em um percurso de profundidade em ordem
    no *p = tree;
    if(p != NULL){
        if(strcmp(p->word, w) == 0){
            printf("%s %ld\n", p->word, p->freq);
            return 1;
        }
        if(search_inOrder(w, p->left))
            return 1;
        if(search_inOrder(w, p->right))
            return 1;
    }


    // printf("%s not found.\n", w);
    return 0;
}


void merge_sort(){

}

int auto_complete(no*tree, char *x, char*** words,long **freqs, long *i, long n){
    //Cria as duas listas de palavras e frequencias que serão ordenadas posteriormente
    if(tree == NULL) 
        return 1;
    
    int c = strncmp(x, tree->word, n);
    if(c<=0 && !auto_complete(tree->left, x, words, freqs, i, n))
        return 0;


    if(c==0){
        (*words)[*i] = tree->word;
        (*freqs)[*i] = tree->freq;
        (*i)++;
        long *temp_f = realloc(*freqs, (*i+1) * sizeof(long));
        char **temp_w = realloc(*words, (*i+1) * sizeof(char*));
        if(temp_f == NULL || temp_w == NULL){
            free(*words);
            free(*freqs);
            return 0;
        }
        *words = temp_w;
        *freqs = temp_f;      
    }

    if(c>=0 && !auto_complete(tree->right, x, words, freqs, i, n))
        return 0; 
            
    return 1;
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
        else if(strcmp(comando, "AUTOCOMPLETE") == 0){
            char *x = malloc(1000 * sizeof(char));
            char **words = malloc(1 * sizeof(char*));
            long *freqs = malloc(1 * sizeof(long));
 
            long k, i = 0; //k só usado para ordenar depois a ordem
            scanf("%999s %ld", x, &k);
            auto_complete(tree, x, &words, &freqs, &i, strlen(x));


            free(x);
            free(words);
            free(freqs);
            
        }
    }
}
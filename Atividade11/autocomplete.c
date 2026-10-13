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
    if(c == 0){ //Mesma palavra
        tree->freq = f;
        free(w);
    }
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
        if(strcmp(p->word, w) > 0)
            return search_inOrder(w, p->left);
        else
            return search_inOrder(w, p->right);
    }
    else    
        return 0;
        
}

void ordenar_vetores(char **words, long *freqs, long l, long m, long k){
    //Função para separar vetores, e ordena-los
    long n1 = m - l + 1;
    long n2 = k - m;

    long *esq_oco = malloc(n1 * sizeof(long));
    long *dir_oco = malloc(n2 * sizeof(long));
    char **esq_pala = malloc(n1 * sizeof(char*));
    char **dir_pala = malloc(n2 * sizeof(char*));
    
    //Divide os vetores em dois
    for (int i = 0; i <n1; i++){
        esq_oco[i] = freqs[l + i];
        esq_pala[i] = words[l + i];
    }

    for(int j = 0; j <n2; j++){
        dir_oco[j] = freqs[m + 1 + j];
        dir_pala[j] = words[m + 1 + j];
    }

    int i = 0, j = 0, f = l;

    //Intercala os vetores pelo seu tamanho
    while(i < n1 && j < n2){
        if(esq_oco[i] >= dir_oco[j]){
            freqs[f] = esq_oco[i];
            words[f] = esq_pala[i];
            f++;
            i++;
        }
        else{
            freqs[f] = dir_oco[j];
            words[f] = dir_pala[j];
            f++;
            j++;
        }
    }

    //Aloca os elementos que sobraram
    while (i<n1){
        freqs[f] = esq_oco[i];
        words[f] = esq_pala[i];
        i++;
        f++;
    }
    while(j<n2){
        freqs[f] = dir_oco[j];
        words[f] = dir_pala[j];
        j++;
        f++;
    }
    free(dir_oco);
    free(dir_pala);
    free(esq_oco);
    free(esq_pala);
}


void merge_sort(char **words, long*freqs, long l, long k){
    //Função de ordenação mergesort, que ordena vetores os quebrando em partes
    if (l < k){
        long m = l + (k - l) / 2;
        
        merge_sort(words, freqs, l, m);
        merge_sort(words, freqs, m +1, k);

        ordenar_vetores(words, freqs, l, m, k);
    }
}

int auto_complete(no*tree, char *x, char*** words,long **freqs, long *i, long n){
    //Cria as duas listas de words e frequencias que serão ordenadas posteriormente
    if(tree == NULL) 
        return 1;
    
    int c = strncmp(x, tree->word, n);
    if(c<=0 && !auto_complete(tree->left, x, words, freqs, i, n))
        return 0;


    if(c==0){ //Achou uma palavra, coloca ela na lista
        (*words)[*i] = tree->word;
        (*freqs)[*i] = tree->freq;
        (*i)++;
        long *temp_f = realloc(*freqs, (*i+1) * sizeof(long));
        char **temp_w = realloc(*words, (*i+1) * sizeof(char*));
        if(temp_f != NULL) 
            *freqs = temp_f;
        if(temp_w != NULL) 
            *words = temp_w;
        if(temp_f == NULL || temp_w == NULL)
            return 0;
    }

    if(c>=0 && !auto_complete(tree->right, x, words, freqs, i, n))
        return 0; 
            
    return 1;
}

int search_Todelete(char *w, no** p, no** pai){
    //Faz a busca do nó que queremos apagar, guardando o seu pai, que será util quando for fazer a função delete()
    if(*p != NULL){
        if(strcmp((*p)->word, w) == 0){         
            return 1;
        }
        *pai = *p;
        if(strcmp((*p)->word, w) > 0){
            *p = (*p)->left;
            return search_Todelete(w, p, pai);
        }
        else{
            *p = (*p)->right;
            return search_Todelete(w, p, pai);
        }   
    }
    else    
        return 0;
}

void achar_predecessor(no **p_p, no **pai_p){
    //Acha o predecessor do ramo escolhido
    *pai_p = *p_p; 
    *p_p = (*p_p) ->left;
    while((*p_p)->right != NULL){
        *pai_p = *p_p; 
        *p_p = (*p_p) ->right;
    }
}

void delete(no* pai, no* p, no** tree){
    //Apaga o nó em 4 diferentes casos
    if(p->left == NULL && p->right == NULL){ //nó sem filhos
        if(p == *tree)
            *tree = NULL;
        else if(pai->left == p)
            pai->left = NULL;
        else
            pai->right = NULL;        
        free(p->word);
        free(p);
    }

    else if(p->left != NULL && p->right == NULL){ //nó só com filho do esquerda
        if(p == *tree)
            *tree = p->left;
        else if(pai->left == p){
            pai->left = p->left;
        }
        else{
            pai->right = p->left;
        }
        free(p->word);
        free(p);
    }

    else if(p->right != NULL && p->left == NULL){ //nó só com filho da direita
        if(p == *tree)
            *tree = p->right;
        else if(pai->left == p){
            pai->left = p->right;
        }
        else{
            pai->right = p->right;
        }
        free(p->word);
        free(p);
    }

    else{ //o pai tem ambos os nós (ACHANDO O PRECESSOR - MAIOR VALOR QUE É MENOR QUE O QUE VAMOS APAGAR)
        no *p_p = p; //p_p é o nó prodecessor e pai_p é o pai do prodecessor
        no *pai_p = NULL;
        achar_predecessor(&p_p, &pai_p);

        //Tira o prodecessor da posição antiga
        if(pai_p != p){
            pai_p->right = p_p->left;
            p_p->left = p->left;
        }
        p_p->right = p->right;

        //coloca o prodecessor no luga de p
        if(p == *tree)
            *tree = p_p;
        else if(pai->left == p)
            pai->left = p_p;
        else 
            pai->right = p_p;
        
        free(p->word);
        free(p);   
    }
}

void print_lexicografico(no *tree){
    //A partir de um percorrimento em-ordem, printa toda a árvore em ordem lexografica
   if(tree != NULL){
        print_lexicografico(tree->left);
        printf("%s ", tree->word);
        print_lexicografico(tree->right);
   }
}

void liberar_arvore(no *tree){
    //Ao finalizar o programa libera toda a memória alocada para a árvore
    if(tree!=NULL){
        liberar_arvore(tree->left);
        liberar_arvore(tree->right);
        free(tree->word);
        free(tree);
    }
}

int main(){
    char comando[20];
    no *tree = NULL;

    while(scanf("%19s", comando) != EOF){
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
            free(w);
        }   
        else if(strcmp(comando, "AUTOCOMPLETE") == 0){
            char *x = malloc(1000 * sizeof(char));
            char **words = malloc(1 * sizeof(char*));
            long *freqs = malloc(1 * sizeof(long));
 
            long k, i = 0; //k só usado para ordenar depois a ordem
            scanf("%999s %ld", x, &k);
            auto_complete(tree, x, &words, &freqs, &i, strlen(x));
            merge_sort(words, freqs, 0, i - 1);
            if(i>0){
                for(long j= 0; j<k && j<i;j++){
                    printf("(%s,%ld) ", words[j], freqs[j]);
                }
                printf("\n");
            }
            else
                printf("nothing for %s.\n", x);
            free(x);
            free(words);
            free(freqs);
        }
        else if(strcmp(comando, "PRINT") == 0){
            if(tree == NULL)
                printf("the dictionary is empty.\n");
            else{
                print_lexicografico(tree);
                printf("\n");
            }

        }
        else if(strcmp(comando, "DELETE") == 0){
            char *w = malloc(1000 * sizeof(char));
            scanf("%999s", w);
            no *pai = NULL;
            no *p = tree;
            search_Todelete(w, &p, &pai);
            free(w);
            if(p!=NULL)
                delete(pai, p, &tree);
        }

    }
    liberar_arvore(tree);
    return 0;
}
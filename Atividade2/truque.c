#include <stdio.h>
#include <math.h>

void ler_entradas(int n, int vetor[n]){
    /*Recebe as entradas do tamanho da lista e adiciona seus elementos*/
    int i;
    for(i=0; i<n; i++){ 
        scanf("%d", &vetor[i]);
        }
    }
    
    //Adicionar a entrada para quando ocasionar em uma soma e quando for uma atualização

int criar_r(int n, int vetor[n]){
    double raiz = sqrt(n);
    int raiz_r = round(raiz);
    int vetor_r[raiz_r];

    int i, inicio=0,fim=5, soma=0;

    //Zera todos os valores do vetor r, para não dar problema na memória
    for(i=0; i<= raiz_r; i++){
        vetor_r[i] = 0;
    }

    //Adiciona os valores do vetor V, por meio de somas, no vetor r
    for(i=0; i<raiz_r; i++){
        while(inicio<fim){
            vetor_r[i] += vetor[inicio];
            inicio++;
        }
        fim +=5;
    }
    for(i=0; i<raiz_r; i++){ 
        printf("%d\n", vetor_r[i]);
        }



}

    
int somar(){
    
}

int atualizar(){

    
}
    
int main(void){
    int n;
    scanf("%d", &n);
    int vetor[n];

    ler_entradas(n, vetor);

    criar_r(n, vetor);
    
    
    return 0;
}
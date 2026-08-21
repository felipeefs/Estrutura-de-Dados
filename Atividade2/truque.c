#include <stdio.h>
#include <math.h>

int ler_entradas(){
    /*Recebe as entradas do tamanho da lista e adiciona seus elementos*/
    int n;
    scanf("%d", &n);
    int vetor[n];

    int i;
    for(i=0; i<n; i++){ 
        scanf("%d", &vetor[i]);
        }

    return n, vetor[n];
    }
    

    //Adicionar a entrada para quando ocasionar em uma soma e quando for uma atualização

int criar_r(int n, int vetor[n]){
    double raiz = sqrt(n);
    int raiz_r = round(raiz);
    int vetor_r[raiz_r];

    int i, inicio=0,fim=5, soma=0;
    for(i=0; i<raiz_r; i++){
        while(inicio<fim){
            vetor_r[i] += vetor[inicio];
            inicio++;
        }
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
    
    /*double i = 22;
    printf("%f\n",(int)sqrt(i));*/
    ler_entradas();


    
    
    
    return 0;
}
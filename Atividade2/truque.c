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

int criar_r(int n, int vetor[n], int raiz_r, int vetor_r[raiz_r]){
    int i, inicio=0,fim=5, soma=0;

    //Zera todos os valores do vetor r, para não dar problema na memória
    for(i=0; i<= raiz_r; i++){
        vetor_r[i] = 0;
    }

    //Adiciona os valores do vetor V, por meio de somas, no vetor r. Somas de 5 em 5
    for(i=0; i<raiz_r; i++){
        while(inicio<fim && inicio < n){
            vetor_r[i] += vetor[inicio];
            inicio++;
        }
        fim +=5;
    }
    //Prints para testar
    for(i=0; i<raiz_r; i++){ 
        printf("%d\n", vetor_r[i]);
        }
}

    
int somar(int i ,int n, int j, int vetor[n], int raiz_r, int vetor_r[raiz_r]){
    //Existem 4 casos; i e j multiplos do vetor_r; i multiplo e j não; j multiplo e i não; nenhum dos dois multiplos
    int soma = 0, k ,ind_inicial, ind_final;

    //Se ambos forem multiplos pode-se somar pelo vetor_r diretamente
    if(i % raiz_r == 0 && (j+1) % raiz_r ==0){
        ind_inicial = i / raiz_r;
        ind_final = ((j+1) / raiz_r) -1;
        for(k=ind_inicial; k<=ind_final; k++){
            soma += vetor_r[k];
            printf("%d\n", vetor_r[k]);
        }
    printf("%d\n", soma);
    }
    
}

int atualizar(){

    
}
    
int main(void){
    //Entradas do tamanho do vetor V
    int n;
    scanf("%d", &n);
    int vetor[n];

    //Le as entradas e cria um vetor r, com base em V
    int raiz_r = (int)round(sqrt(n));   
    int vetor_r[raiz_r];
    ler_entradas(n, vetor);
    criar_r(n, vetor, raiz_r, vetor_r);

    //Operações de soma e de atualização
    int i ,j_x;
    char operacao;
    scanf("%s %d %d", &operacao, &i, &j_x);

    if(operacao == 's')
        somar(i, n, j_x, vetor, raiz_r, vetor_r);
    /*if(operacao == 'a')
        atualizar();
    */
    return 0;
}
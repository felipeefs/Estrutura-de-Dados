#include <stdio.h>
#include <math.h>

void ler_entradas(int n, int vetor[n]){
    /*Recebe as entradas do tamanho da lista e adiciona seus elementos*/
    int i;
    for(i=0; i<n; i++){ 
        scanf("%d", &vetor[i]);
        }
    }
    
void criar_r(int n, int vetor[n], int raiz_r, int vetor_r[raiz_r]){
    int i, inicio=0, fim=raiz_r;

    //Zera todos os valores do vetor r, para não dar problema na memória
    for(i=0; i< raiz_r; i++){
        vetor_r[i] = 0;
    }

    //Adiciona os valores do vetor V, por meio de somas, no vetor r. Somas de 5 em 5
    for(i=0; i<raiz_r && inicio <n; i++){
        while(inicio<fim && inicio < n){
            vetor_r[i] += vetor[inicio];
            inicio++;
        }
        fim +=raiz_r;
    }
}

    
void somar(int i ,int n, int j, int vetor[n], int raiz_r, int vetor_r[raiz_r]){
    //Existem 2 casos; ou i e j estão no mesmo bloco, ou estão em blocos diferentes 
    int soma = 0;
    int bloco_i = i / raiz_r;
    int bloco_j = j / raiz_r;

    //Quando os limites ocasionam no mesmo bloco; em que pode ser que não seja o bloco inteiro
    if(bloco_i == bloco_j){ 
        for(int k=i; k<=j; k++){ //Soma direto sem se preucupar com pontas foras do vetor
            soma += vetor[k];
        }
    }

    else{
        //Elementos antes dos blocos (caso não existam a condição do for nem faz a soma)
        for(int k=i; k < (bloco_i + 1) * raiz_r; k++){
            soma += vetor[k];
        }

        //Elementos que estão nos blocos do vetor_r
        for(int k = bloco_i+1; k< bloco_j; k++){
            soma+= vetor_r[k];
        }

        //Elementos que passam dos blocos
        for(int k = bloco_j * raiz_r; k <=j; k++){
            soma += vetor[k];
        }

    }
    printf("%d\n", soma);

}

void atualizar(int i, int x, int n, int vetor[n], int raiz_r, int vetor_r[raiz_r]){
    //Descobrir onde está o i em r, e subtrair vetor[i] e somar x

    int indice_r = i / raiz_r; //Ao transformar em int, descobre-se em que posição ele está em vetor_r
    vetor_r[indice_r] += (x - vetor[i]);
    vetor[i] = x;

}
    
int main(void){
    //Entradas do tamanho do vetor V
    int n;
    scanf("%d", &n);
    int vetor[n];

    //Le as entradas e cria um vetor r, com base em V
    int raiz_r = (int)ceil(sqrt(n));   
    int vetor_r[raiz_r];
    ler_entradas(n, vetor);
    criar_r(n, vetor, raiz_r, vetor_r);

    //Operações de soma e de atualização
    int i ,j_x;
    char operacao;

    //Enquanto for verdade, o programa irá pedir entradas e devolverá saidas:
    while (scanf(" %c %d %d", &operacao, &i, &j_x) != EOF){ 
        if(operacao == 's')
            somar(i, n, j_x, vetor, raiz_r, vetor_r);
        if(operacao == 'a')
            atualizar(i, j_x, n , vetor, raiz_r, vetor_r);
        }
    
    return 0;
}
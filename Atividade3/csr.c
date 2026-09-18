#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int linha;
    int coluna;
    int valor;
} matriz;

int comparar_inteiros(const void *a, const void *b){
    matriz *e1 = (matriz *)a;
    matriz *e2 = (matriz *)b;

    // Compara duas linhas
    if(e1->linha != e2 -> linha){
        return e1 -> linha - e2 -> linha;
    }
    //Se as linhas forem iguais, ordena-se as colunas
    return e1 -> coluna - e2 -> coluna;
}

void realocar_vetorR(int *R, int k, int *L, int i_max){
    //Preenche o vetor R a partir da ocorrencia das linhas da matriz (tal linhas que estão guardadas em L)
    R[0] = 0; //O vetor R sempre começa zerado

    int posicao = 1;
    int ocorrencia = 1;
    for(int f = 0; f < k; f++){
        if(L[f] == L[f+1] && (L[f]+1) == posicao && f < k -1){
            ocorrencia += 1;
        }
        else if(L[f] != L[f+1] && (L[f]+1) == posicao){
            R[posicao] = ocorrencia;
            ocorrencia += 1;
            posicao += 1;
        }
        else{
            R[posicao] = ocorrencia - 1;
            posicao += 1;
            f --;
        }
    }
    //Caso as ultimas linhas sejam vazias elas são preenchidas
    while (posicao < i_max + 1){
        R[posicao] = ocorrencia -1;
        posicao ++;
    }
    
}

int procurar_Nnulos(int *R, int i, int i_max){
    //Na linha em que queremos achar o valor, verifica-se se há elementos não nulos e devolve sua quantidade
    if(i < (i_max +1))
        return (R[i+1] - R[i]); 
    else
        return 0;  
}

int procurar_coluna(int *R, int *C, int j, int i){
    //A partir dos valores de R, procura-se a ocorrência de j na lista das colunas (C), e devolve-se a posicção em que ele foi encontrado
    for(int f = R[i]; f <= (R[i+1] - 1); f++){
        if (C[f] == j){
            return f;
        }
    }
    return -1; //Devolve-se -1 para a condição na main ser analisada
}

int main(){
    int k, i_max = 0;
    scanf(" %d", &k);
    int *A = malloc(k * sizeof(int)); //Armazena os valores de x
    int *C = malloc(k * sizeof(int)); //Armazena os valores das colunas
    int *L = malloc(k * sizeof(int)); //Armazena os valores das linhas

    if(A == NULL|| C == NULL || L == NULL)
        return 1;

    //Entradas
    for(int f = 0; f < k; f++){
        scanf(" %d %d %d", &L[f], &C[f], &A[f]);
 
        if(L[f] > i_max){
            i_max = L[f];
        }
    }
    
    //Ordena os elementos da lista
    matriz *temporaria = malloc(k * sizeof(matriz));
    for(int f = 0; f < k; f++){
        temporaria[f].linha = L[f];
        temporaria[f].coluna = C[f];
        temporaria[f].valor = A[f];
    }
    qsort(temporaria, k, sizeof(matriz), comparar_inteiros);
    for(int f = 0; f <k; f++){
        L[f] = temporaria[f].linha;
        C[f] = temporaria[f].coluna;
        A[f] = temporaria[f].valor;
    }  
    free(temporaria);

    //Cria o vetor R, e a partir do vetor L ele é preenchido
    int *R = calloc((i_max +2), sizeof(int));
    realocar_vetorR(R, k, L, i_max);

    //Entradas de i e j, para serem procurados
    int i, j;
    while(scanf(" %d %d", &i ,&j) != EOF){
        if(i == -1 && j == -1)
            break;
        
        int quantidade_deNumeros = procurar_Nnulos(R, i, i_max);
        if(quantidade_deNumeros){
            int valor_j = procurar_coluna(R, C, j, i);
                if(valor_j != -1){
                    printf("(%d,%d) = %d\n",i, j, A[valor_j]);
                }
                else{ 
                    printf("(%d,%d) = 0\n", i, j);
                }
        }

        else{
            printf("(%d,%d) = %d\n",i, j, quantidade_deNumeros);
        }
    }

    //Liberação de memória
    free(C);
    free(L);
    free(A);
    free(R);

}
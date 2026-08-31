#include <stdio.h>
#include <string.h>

typedef struct{
        char nome[51];
        char endereco[101];
        long telefone;
        char data[9];

    }contato;

void adicionar_contato(contato contatos[], int num_contatos){
    //Adiciona um contato com base no struct contato, em que as entradas tem um limite de caracteres que deve ser respeitado
    scanf(" %50[^\n]", contatos[num_contatos].nome);
    scanf(" %100[^\n]", contatos[num_contatos].endereco);
    scanf(" %ld", &contatos[num_contatos].telefone);  
    scanf(" %8[^\n]", contatos[num_contatos].data);     

    printf("Contato para %s inserido.\n\n", contatos[num_contatos].nome);
}

void remover_contatos(contato contatos[], int *num_contatos){
    char nome_procurado[51];
    scanf(" %50[^\n]", nome_procurado);
    int apagos = 0;
    int indice_procurado = 0;

    for(indice_procurado; indice_procurado < *num_contatos; indice_procurado ++){
        if(strcmp(nome_procurado, contatos[indice_procurado].nome) == 0 && indice_procurado == *num_contatos -1){
            //Caso para quando o ultimo contato for o procurado, ele não será removida de lista (não é possível), mas a contagem de num_contatos diminui
            (*num_contatos) --;
            apagos ++;
            printf("Encontrou nome igual\n");
        }

        else if(strcmp(nome_procurado, contatos[indice_procurado].nome) == 0){
            //Sobrescreve os valores, quando o contato for removido
            for(int i = indice_procurado; i < *num_contatos - 1; i++){
                contatos[i] = contatos[i+1];
            }
            (*num_contatos)--;
            apagos ++;
            printf("Encontrou nome igual\n");
        }
    }

    printf("Contatos de %s removidos: %d\n", nome_procurado, apagos);

}

void buscar_contatos(contato contatos[], int num_contatos){
    char nome_procurado[51];
    scanf(" %50[^\n]", nome_procurado);

    for(int i = 0; i < num_contatos; i++){
        if(strcmp(nome_procurado, contatos[i].nome) == 0){
            printf("Resultado da busca:\n");
            printf("(%d) %s	%s	%ld	%s\n\n", i+1, contatos[i].nome, contatos[i].endereco, contatos[i].telefone, contatos[i].data);
        }
        else{
            printf("Resultado da busca:\n");
            printf("Nenhum contato.\n\n");
        }

    }

}

int main(){
    char operacao;
    contato contatos[1000];
    int num_contatos = 0;

    while ((scanf(" %c", &operacao) != EOF))
    {
        switch (operacao){
        case 'i':
            adicionar_contato(contatos, num_contatos);
            num_contatos ++;
            break;
        case 'r':
            remover_contatos(contatos, &num_contatos);
            break;
        case 'b':
            buscar_contatos(contatos, num_contatos);
        default:
            break;
        }
    }
    for(int i = 0; i < num_contatos; i++){
        printf("----------\n");
        printf("%s\n", contatos[i].nome);
        printf("%s\n", contatos[i].endereco);
        printf("%ld\n", contatos[i].telefone);  
        printf("%s\n", contatos[i].data);   
        printf("O numero de contatos é: %d\n", i + 1);  
    }

    
}
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
        if(strstr(contatos[indice_procurado].nome, nome_procurado) !=0 && indice_procurado == *num_contatos -1){
            //Caso para quando o ultimo contato for o procurado, ele não será removida de lista (não é possível), mas a contagem de num_contatos diminui
            (*num_contatos) --;
            apagos ++;
        }

        else if(strstr(contatos[indice_procurado].nome, nome_procurado) != 0){
            //Sobrescreve os valores, quando o contato for removido
            for(int i = indice_procurado; i < *num_contatos - 1; i++){
                contatos[i] = contatos[i+1];
            }
            (*num_contatos)--;
            apagos ++;
            indice_procurado --;
        }
    }

    printf("Contatos de %s removidos: %d.\n\n", nome_procurado, apagos);

}

void buscar_contatos(contato contatos[], int num_contatos){
    //Com base no nome inserido, lista todos os dados desse contato, caso ele exista
    char nome_procurado[51];
    scanf(" %50[^\n]", nome_procurado);
    int condicao = 1;
    
    printf("Resultado da busca:\n");
    for(int i = 0; i < num_contatos; i++){
        if(strstr(contatos[i].nome, nome_procurado) != 0){
            printf("(%d) %s	%s	%ld	%s\n\n", i+1, contatos[i].nome, contatos[i].endereco, contatos[i].telefone, contatos[i].data);
            condicao = 0;
        }

    }
    if(condicao){
        printf("Nenhum contato.\n\n");

    }
}

void listar_contatos(contato contatos[], int num_contatos){
    //Um loop que lista todos os contatos
    printf("Listagem:\n");
    if(num_contatos != 0){ 
        for(int i = 0; i < num_contatos; i++){
            printf("(%d) %s	%s	%ld	%s\n", i+1, contatos[i].nome, contatos[i].endereco, contatos[i].telefone, contatos[i].data);
            printf("\n");
        }
    }

    else{
        printf("Nenhum contato.\n");
    }    
}

int main(){
    char operacao;
    contato contatos[1000];
    int num_contatos = 0;

    while ((scanf(" %c", &operacao) != EOF))
    {
        if(operacao == 'f')
            break;

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
                break;
            case 'p':
                listar_contatos(contatos, num_contatos);
                break;  
            default:
                break;
        }
    }
}
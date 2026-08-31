#include <stdio.h>

typedef struct{
        char nome[51];
        char endereco[101];
        long telefone;
        char data[9];

    }contato;

void adicionar_contato(contato contatos[], int num_contatos){
    scanf(" %50[^\n]", contatos[num_contatos].nome);
    scanf(" %100[^\n]", contatos[num_contatos].endereco);
    scanf(" %ld", &contatos[num_contatos].telefone);  
    scanf(" %8[^\n]", contatos[num_contatos].data);     
    num_contatos ++;

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
            break;
        
        default:
            break;
        }
    }
            printf("%s\n", contatos[num_contatos].nome);
            printf("%s\n", contatos[num_contatos].endereco);
            printf("%ld\n", contatos[num_contatos].telefone);  
            printf("%s\n", contatos[num_contatos].data);     
    
}
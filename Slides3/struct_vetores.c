#include <stdio.h>
#include <string.h>

struct tarefa {
    char descricao[30];
    int duracao;
};

struct pessoa {
    char nome[50];
    int idade;
    struct tarefa tarefas[5];
};

int main(void) {
    struct pessoa P[10];
    
    strcpy(P[1].nome, "J. Pinto Fernandes");
    P[1].idade = 51;
    strcpy(P[1].tarefas[0].descricao, "fazer lab 3");
    P[1].tarefas[0].duracao = 1;


    printf("O nome da segunda pessoa é: %s\n", P[1].nome);
    printf("A idade da segunda pessoa é: %d\n", P[1].idade);

    printf("A descrição da sua primeira tarefa é: %s\n", P[1].tarefas[0].descricao);
    printf("A duração da sua primeira tarefa é: %d\n", P[1].tarefas[0].duracao);

} 
#include <stdio.h>
#include <string.h>

struct pessoa{
    char nome[50];
    int idade;  
};

int main(){
    struct pessoa p1;

    strcpy(p1.nome, "J. Pinto Fernandes");
    p1.idade = 51;
    printf("%s %d\n", p1.nome, p1.idade);

    struct pessoa p2 = p1;
    strcpy(p2.nome, "Lili");
    printf("%s %d\n", p2.nome, p2.idade);

    struct pessoa* ap = &p1;
    ap->idade = 131; // eq. a (*ap).idade = 131; Da ao apontador uma idade (que já existe, nova)
    printf("%s %d\n", ap->nome, ap->idade);

    printf("Há mudanças na p1: %s %d\n", p1.nome, p1.idade); //Ao apontar *ap para o endereço de p1, ao mudar *ap, automaticamente muda p1

}
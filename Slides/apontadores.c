#include <stdio.h>
/*Um apontador é uma variável que guarda um endereço de memória

  Um apontador int pode guardar o endereço de uma variável int, ou elemento int de um vetor ou um campo de registro int

    x→ 10
    &x→ endereço de x
    p→ endereço de x
    *p→ 10
*/


int endereco(void){
    int x = 10;

    int* pi = &x; //Foi criado um ponteiro pi, que armazena o valor de x, com base no local onde x está armazenado
    int** ppi = &pi; //O ponteiro ppi o valor de pi, com base no local onde pi está armazenado

    printf("Valor de x: %d\n", x);
    printf("Valor do endereço de x: %p\n\n", &x);

    printf("Valor de pi: %p\n", pi);
    printf("Endereco de pi: %p\n", &pi);
    printf("Valor do int apontado por pi: %d\n\n", *pi);
    
    printf("Valor em ppi: %p\n", ppi);
    printf("Endereco de ppi: %p\n", &ppi);
    printf("Valor do int apontado pelo apontador apontado por ppi: %d\n", **
    ppi);}


int main(void){
    endereco();
    return 0;
}
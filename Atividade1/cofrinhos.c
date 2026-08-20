#include <stdio.h>

int comparacoes(int num_teste){
    //Declaração de váriaveis e primeira entrada
    int testes, j, z, diferenca, soma =0, sub =0;
    num_teste += 1;
    scanf("%d", &testes);

    //Caso geral da recursão, caso o teste for diferente de 0, deve se digitar um conjunto de dois números para serem subtraidos (comparados) e adicionados (+) na próxima comparação
    if (testes != 0){
        printf("Teste %d\n", num_teste);

        while (testes>0){
            scanf("%d %d",&j ,&z);

            diferenca = (j+soma) - (z+sub);
            printf("%d\n", diferenca);
            testes--;

            if (diferenca<0){
                sub = diferenca * (-1);
                soma = 0;
            }
            else{
                soma = diferenca;
                sub = 0;
            }
        }
        printf("\n"); //Printa uma linha em branco entre Testes
        comparacoes(num_teste); //Recursão que chama de novo para um novo teste 
    }
}

int main(){
    //Chama a função inicialmente com o parâmetro 0, pois ele é o número do teste que será printado; ele é acumulado conforme se chama a função na recursão
    comparacoes(0);
    return 0;
}
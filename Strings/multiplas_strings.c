#include <stdio.h>

int main(void) {
    char nomes[][10] = {"Carlos","Dora","Lia","Lea",""};

    printf("%c\n", nomes[0][3]); //Lida como uma matriz
    printf("%s\n", nomes[2]); 

    char* pessoas[] = {"Carlos","Dora","Lia","Lea",""};
    
    printf("%c\n", pessoas[0][3]);
    printf("%s\n", pessoas[2]);
}
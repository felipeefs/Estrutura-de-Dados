#include <stdio.h>
#include <string.h>

int main(void) {
    /*Ao final da string a um /0 que indica que a string acabou, nesses loops ao encontra-las o loop para   */
    char s[] = "abcdef";

    for (int i=0; s[i] != '\0'; i++)
        printf(">%c<\n",s[i]);

    printf("\n");
        
    for (int i=0; i<strlen(s); i++) //strlen(s) para ler o tamanho de uma string
        printf(">%c<\n",s[i]);
}
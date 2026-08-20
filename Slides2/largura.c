#include <stdio.h>
int main(void) {
    /*Um número quanto do indicador da várivel indica quantas casas para a esquerda ela vai dar um espaçamento*/
    int i = 13;
    printf(">%1d< >%1d< \n", i, -i);
    printf(">%7d< >%7d< \n", i, -i);
    printf(">%11d< >%11d< \n\n", i, -i);
    
    float f = 3.1416;
    printf(">%1f< >%1f< \n", f, -f);
    printf(">%7f< >%7f< \n", f, -f);
    printf(">%11f< >%11f< \n\n", f, -f);
    
    char s[] = "abcd";
    printf(">%1s< \n", s);
    printf(">%7s< \n", s);
    printf(">%11s< \n", s);

    return 0;
}
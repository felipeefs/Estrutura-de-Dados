#include <stdio.h>
int main(void) {
    /*Pontos e um número após o % indica a quantidade de casas que serão impressas*/
    int i = 7;
    
    printf(">%.1d< >%.1d< \n", i, -i);
    printf(">%.2d< >%.2d< \n", i, -i);
    printf(">%.3d< >%.3d< \n\n", i, -i);
    
    float f = 3.1416;
    printf(">%.1f< >%.1f< \n", f, -f);
    printf(">%.2f< >%.2f< \n", f, -f);
    printf(">%.3f< >%.3f< \n\n", f, -f);
    
    char s[] = "abcd";
    printf(">%.1s< \n", s);
    printf(">%.2s< \n", s);
    printf(">%.3s< \n", s);
    printf(">%.5s< \n", s);
    return 0;
}
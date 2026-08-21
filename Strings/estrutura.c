#include <stdio.h>

int main(void) {
    /*Strings em c são criadas como listas, em que há um /0 no final
     --- char s[] = "abc"; equivale a char s[] = {'a', 'b', 'c', '\0'};
    */

    
    char s[10] = "abcd"; 

    s[1] = ' ';
    s[4] = 'z';
    s[5] = s[0];
    s[6] = s[2] + 13;
    s[7] = '\0';

    printf(">%s<\n", s);
    
    return 0;
}
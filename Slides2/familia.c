#include <stdio.h>
int main(void) {
    printf("%2$d %4$d %1$d %3$d \n\n", 10, 20, 30, 40);
    
    printf("%2$d %4$d %2$d %4$d \n\n", 10, 20, 30, 40);
    
    return 0;
}
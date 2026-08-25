#include <stdio.h>

int main(void) {
    enum dias {dom,seg,ter,qua,qui,sex,sab};
    enum dias d1, d2;

    d1 = dom;
    d2 = qui;

    if (d1 == d2)
        ;

    while (d1 < sab) {
        d1++;
        printf("%d\n", d1);
    }

    return 0;
}
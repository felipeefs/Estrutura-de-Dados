#include <stdio.h>

void push(int pilha[], int *topo, int x)
{
    (*topo)++;
    pilha[*topo] = x;
}

int pop(int pilha[], int *topo)
{
    int rem;

    rem = pilha[*topo];
    (*topo)--;

    return rem;
}

int main(void)
{
    int pilha[5];
    int topo = -1;

    push(pilha, &topo, 10);
    push(pilha, &topo, 20);
    push(pilha, &topo, 30);

    printf("%d\n", pop(pilha, &topo));
    printf("%d\n", pop(pilha, &topo));

    return 0;
}
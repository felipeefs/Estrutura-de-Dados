#include <stdio.h>

int ler_bandejas(){
    //Lê todas a quantidade de bandejas
    int bandejas;
    if (scanf("%d", &bandejas) == 1){ 
        return bandejas;
    }
    return 0;
}

int quebras(int j){
    //Conforme a quantidade de bandeja (faz um loop), e soma quantos copos foram quebrados
    int acumula = 0;
    int lata, copo, i;

    for(i =0; i < j; i++){
        if (scanf("%d %d", &lata, &copo) ==2){
            if(lata > copo){
                acumula += copo;
            } 
        }
    }
    return acumula;
}

int main(){
    int n_ban = ler_bandejas();
    printf("%d\n", quebras(n_ban));

    return 0;
}


#include <stdio.h>
#include <math.h>

int entradas(){
    int n;
    scanf("%d", &n);
    int vetor[n];

    int i, elemento;
    while(i<20 && (scanf("%d", &elemento) == 1)){
        vetor[i] = elemento;
        i++;
    }
    
    printf("%d", vetor);


}
int main(void){
    double i = 22;
    printf("%f\n",(int)sqrt(i));
    entradas();


}
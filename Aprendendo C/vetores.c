/*Um vetor em c não pode crescer e encolher (tamanho fixo), não há comover o tamanho de um vetor após criado (como um len)*/

int main(){
    double pops[50]; //cria um vetor com 50 doubles, de 0 a 49
    pops[0] = 809494;
    pops[1] = pops[0] + 11804445;


    int i;
    int vals[5];
    for (i =0; i<=5; i++){
        vals[i] = 0;
        printf("%d\n", vals[i]);
    }
    printf("%d\n", i); //Nesse caso o i chega até 6, mas em C não ocorre erro mesmo ultrapassando os limites do vetor
    return 0;
}
double expon(double b, int e) {
    if (e == 0){
        return 1.0;
    }
    else{
        return b * expon(b, e - 1);
    }
}

int euclides(int a, int c) {
    if (c == 0){
        return a;
    }
    else{
        return euclides(c, a % c);
    }
}

int main(){
    double b = 2;
    int e = 3;
    printf("O número %f elevado a %d é igual a: %f\n", b, e, expon(b,e));

    int a = 24;
    int c = 40;
    printf("O máximo divisor comum entre %d e %d é igual a: %d\n", a, c, euclides(a,c));
}
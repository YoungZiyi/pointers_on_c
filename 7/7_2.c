#include <stdio.h>


int gcd(int M, int N);
int gcd_iter(int M, int N);


int gcd(int M, int N) {
    int R = M % N;
    if (R == 0) {
        return N;
    }
    if (R > 0) {
        return gcd(N, R);
    }
}


int gcd_iter(int M, int N) {
    while (M != N) {
        M, N = N, M % N;
    }
    return N;
}


void main() {
    int i = 100;
    int j = 55;
    int g = gcd(i, j);
    printf("%d\n", g);
    int f = gcd(i, j);
    printf("%d\n", f);
}

#include <stdio.h>


int hermite(int n, int x);


int hermite(int n, int x) {
    if (n <= 0) {// <= 0
        return 1;
    } else if (n == 1) {// == 1
        return 2 * x;
    } else {// >= 2
        return 2 * x * hermite(n-1, x) - 2 * (n - 1) * hermite(n-2, x);
    }
}


void main() {
    int i = hermite(10, 10);
    printf("%d\n", i);
}

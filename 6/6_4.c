#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define USING_TYPE char
// todo: 获取USING_TYPE所有位为1/0
#define ALLSET 0xff
#define ALLUNSET 0x00


void eratosthenes_6_4(int n);
void eratosthenes_6_5(int n);
void eratosthenes_6_6(int n1, int n2);
USING_TYPE is_set(USING_TYPE *short_int_arr, int int_index, int bit_index);
void set_bit(USING_TYPE *short_int_arr, int int_index, int bit_index);
void unset_bit(USING_TYPE *short_int_arr, int int_index, int bit_index);


void eratosthenes_6_4(int n) {
    bool *is_prime = malloc(sizeof(bool) * (n + 1));
    for (int i = 2; i <= n; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    printf("2 ");
    for (int i = 3; i <= n; i += 2) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(is_prime);
}


USING_TYPE is_set(USING_TYPE *short_int_arr, int int_index, int bit_index) {
    USING_TYPE n = short_int_arr[int_index];
    n = n >> bit_index;
    return n & 1;
}


void set_bit(USING_TYPE *short_int_arr, int int_index, int bit_index) {
    USING_TYPE p = 1 << bit_index;
    short_int_arr[int_index] = short_int_arr[int_index] | p;
}


void unset_bit(USING_TYPE *short_int_arr, int int_index, int bit_index) {
    USING_TYPE p = ALLSET;
    USING_TYPE m = 1 << bit_index;
    p = p ^ m;
    short_int_arr[int_index] = short_int_arr[int_index] & p;
}


void eratosthenes_6_5(int n) {
    unsigned int s = sizeof(USING_TYPE);
    unsigned int b = s * 8;
    unsigned int num = n / b + 1;
    USING_TYPE *short_int_arr = malloc(sizeof(USING_TYPE) * num);
    for (int i = 0; i < num; i++) {
        short_int_arr[i] = ALLSET;
    }

    for (int i = 2; i * i <= n; i++) {
        int int_index = i / b;
        int bit_index = i % b;
        if (is_set(short_int_arr, int_index, bit_index)) {
            for (int j = i * i; j <= n; j += i) {
                int int_index = j / b;
                int bit_index = j % b;
                unset_bit(short_int_arr, int_index, bit_index);
            }
        }
    }

    printf("2 ");
    for (int i = 3; i <= n; i += 2) {
        int int_index = i / b;
        int bit_index = i % b;
        if (is_set(short_int_arr, int_index, bit_index)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(short_int_arr);
}


void eratosthenes_6_6(int n1, int n2) {
    unsigned int s = sizeof(USING_TYPE);
    unsigned int b = s * 8;
    unsigned int num = n2 / b + 1;
    USING_TYPE *short_int_arr = malloc(sizeof(USING_TYPE) * num);
    for (int i = 0; i < num; i++) {
        short_int_arr[i] = ALLSET;
    }

    for (int i = 2; i * i <= n2; i++) {
        int int_index = i / b;
        int bit_index = i % b;
        if (is_set(short_int_arr, int_index, bit_index)) {
            for (int j = i * i; j <= n2; j += i) {
                int int_index = j / b;
                int bit_index = j % b;
                unset_bit(short_int_arr, int_index, bit_index);
            }
        }
    }

    int total = 0;
    if (2 >= n1 && 2 < n2) {
        total++;
        printf("2 ");
    }
    for (int i = 3; i <= n2; i += 2) {
        int int_index = i / b;
        int bit_index = i % b;
        if (is_set(short_int_arr, int_index, bit_index)) {
            if (i >= n1 && i < n2) {
                total++;
                printf("%d ", i);
            }
            
        }
    }
    printf("\n");
    printf("%d ~ %d, total:%d\n", n1, n2, total);
    free(short_int_arr);
}


void main() {
    eratosthenes_6_4(100);
    eratosthenes_6_5(100);
    eratosthenes_6_6(50000, 51000);
    eratosthenes_6_6(1000000, 1001000);
    eratosthenes_6_6(100000000, 100001000);
}

#include <stdio.h>


#define MAX_INPUT 1000


void copy_n(char dst[], char src[], int n);


void
main() {
    printf("input src:");
    char src[MAX_INPUT];
    char dst[MAX_INPUT];
    fgets(src, MAX_INPUT, stdin);
    copy_n(dst, src, MAX_INPUT);
    printf("src:%s\n", src);
    printf("dst:%s\n", dst);
}

void copy_n(char dst[], char src[], int n) {
    int dst_i, src_i;
    src_i = 0;
    for (dst_i = 0; dst_i < n; dst_i++) {
        dst[dst_i] = src[src_i];
        if (src[src_i] != 0) {
            src_i++;
        }
    }
}

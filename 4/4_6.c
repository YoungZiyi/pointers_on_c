#include <stdio.h>
#include <stdlib.h>


#define MAX_ROW 1024
#define MAX_CHAR 1024


int substr( char dst[], char src[], int start, int len );


void
main() {
    char src[MAX_CHAR];
    printf("please input src:\n");
    fgets(src, MAX_CHAR, stdin);
    
    char start_s[MAX_CHAR];
    char len_s[MAX_CHAR];
    printf("please input start:\n");
    fgets(start_s, MAX_CHAR, stdin);
    printf("please input len:\n");
    fgets(len_s, MAX_CHAR, stdin);

    int start, len;
    if (sscanf(start_s, "%d", &start) != 1 || sscanf(len_s, "%d", &len) != 1) {
        printf("error start or len\n");
        exit(EXIT_FAILURE);
    }

    printf("===================================RESULT===================================\n");
    printf("src:%s\n", src);
    printf("start:%d\n", start);
    printf("len:%d\n", len);

    char dst[MAX_CHAR];
    int ret = substr( dst, src, start, len );
    printf("ret:%d\n", ret);
    printf("dst:%s\n", dst);
}


int
substr( char dst[], char src[], int start, int len ) {
    int total = 0;
    size_t i = 0;
    for (; i < MAX_CHAR; i++) {
        if (src[i] == '\0') {
            break;
        }
        if (i < start) {
            continue;
        }
        if (!len--) {
            break;
        }
        dst[total++] = src[i];
    }
    dst[total] = '\0';
    return total;
}

/**
 * 编写一个函数，它从一个字符串中提取一个子字符串，函数原型如下：
 *   int substr( char dst[], char src[], int start, int len );
 * 函数任务使从src数组起始位置向后偏移start个字符的位置开始，最多复制
 * len个非NUL字符到dst数组。在复制完后，dst数组必须以NUL字符结尾。
 * 函数的返回值使存储在dst数组中的字符串的长度。
 * 如果start所指定位置超过了src数组的尾部，或者start或len的值为负，
 * 那么复制到dst数组的是个空字符串。
 * 
 */

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

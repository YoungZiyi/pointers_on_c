/**
 * 编写函数copy_n，它的原型如下：
 *   void copy_n(char dst[], char src[], int n);
 * 这个函数用于把一个字符串从数组src复制到数组dst，但有如下要求：
 *   1.必须正好复制n个字符到dst数组中，不能多，不能少；
 *   2.如果src的长度长于或等于n，必须在复制后的字符串尾部补充
 *     足够的NUL字符，使它的长度正好为n；
 *   3.如果src的长度长于或等于n，那么在dst中存储了n个字符后便可
 *     停止，此时，数组dst将不是以NUL结尾
 */

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

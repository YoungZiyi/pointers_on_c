/**
 * 编写一个函数，从一个字符串中去除多余的空格，函数的原型如下：
 *   void deblank(char string[]);
 * 当函数发现字符串中如果有一个地方由一个或多个连续的空格组成时，就把它们
 * 改成单个空格字符。
 * 注意，在便利整个字符串时，要确保它以NUL字符结尾。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void deblank(char string[]);


void main() {
    char string[10] = "a  b  cd  ";
    printf("\n=========origin:%s=========\n", string);
    deblank(string);
    printf("\n=========dblank:%s=========\n", string);
}


// most stupid version
void deblank(char string[]) {
    int len = strlen(string);
    char pre_ch, cur_ch, nex_ch;
    for (int i = 1; i < len; i++) {
        pre_ch = string[i-1];
        cur_ch = string[i];
        if (pre_ch == ' ' && cur_ch == ' ') {
            for (int j = i + 1; j <= len; j++) {
                string[j-1] = string[j];
            }
        }
    }
}

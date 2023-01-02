/**
 * 编写一个程序,从标准输入读取字符,并把它们写道标准输出中.除了大写字母字符
 * 要转换为小写字母,所有字符的输出形式应该和它的输入形式完全相同.
 */

#include <stdio.h>
#include <stdlib.h>

void main() {
    char ch = fgetc(stdin);
    if (ch >= 'A' && ch <= 'Z') {
        ch += 32;
    }
    fputc(ch, stdout);
}

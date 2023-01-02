/**
 * 编写一个程序，从标准输入一行一行读取文本，并完成如下任务：
 * 如果文件中有两行或更多行相邻的文本内容相同，那么就打印其中一行，其余的行
 * 不打印，可以假设文件中的文本行长度不会超过128字符。
 * 文本文件：./text
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ROW 128
#define MAX_CHAR 128


void run();

void
main() {
    run();
}


void
run() {
    int row_num = 0;
    char input[MAX_ROW][MAX_CHAR];
    while ((fgets(input[row_num++], MAX_CHAR, stdin)) != NULL) {
        if (row_num >= MAX_ROW) {
            printf("Row limit\n");
            exit(EXIT_FAILURE);
        }

        

        if ( row_num >= 2 && strcmp(input[row_num - 1], input[row_num - 2]) == 0 ) {
            if ( row_num >= 3 && strcmp(input[row_num - 1], input[row_num - 3]) == 0 ) {
                continue;
            }
            printf("%s", input[row_num-1]);
        }
    }
}

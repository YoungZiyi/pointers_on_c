/**
 * 正数n的平方根可以通过计算一系列近似值来获得，每个近似值都比前一个更加
 * 接近准确值，第一个近似值是1，接下来的近似值则通过下面的公式来获得：
 * a_next = (a + n/a) / 2
 * 
 * 编写一个程序，读入一个值，计算并打印出它的平方根，原则上，这个公式可以
 * 无限进行下去，但在实际中，由于浮点数精度限制，当某个近似值与前一个近似值
 * 相等时，就可以让程序停止。
 */

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>


double my_sqrt(unsigned int number, unsigned int count, double *root);


void
main(int argc,char **argv) {
    if (argc != 3) {
        printf("error param, 2 parameter needed\n");
        exit(EXIT_FAILURE);
    }

    unsigned int number, count;
    if ( sscanf(argv[1], "%d", &number) != 1 || sscanf(argv[2], "%d", &count) != 1 ) {
        printf("wrong param, integer needed\n");
        exit(EXIT_FAILURE);
    }

    double root = 1.;
    my_sqrt(number, count, &root);
    printf("number=>%d\n", number);
    printf("count=>%d\n", count);
    printf("root=>%f\n", root);
}

double
my_sqrt(unsigned int number, unsigned int count, double *root) {
    // 我这里手动设置计算次数，可以改成与上一个root对比的逻辑
    count--;
    *root = (*root + (number / *root)) / 2;
    if (count) {
        my_sqrt(number, count, root);
    }
    return *root;
}

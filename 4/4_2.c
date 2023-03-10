/**
 * 一个整数如果只能被它本身和1整除，它就被成为质数（prime），
 * 编写一个程序，打印出1~100之间的所有质数。
 * 
 */

#include<stdio.h>

void
main(void) {
    for (short int num = 2; num <= 100; num++) {
        short int flag = 1;// 1:prime number 0:composite number
        for (short int i = 2; i <= num; i++) {
            if (num != i && num % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d\n", num);
        }
    }
}

#include <stdio.h>
#include <stdarg.h>


int max_list(int first, ...);


int max_list(int first, ...) {
    int max = first;
    int num;
    va_list list;
    va_start(list, first);
    while ((num = va_arg(list, int)) >= 0) {
        if (num > max) {
            max = num;
        }
    }
    va_end(list);
    return max;
}


void main() {
    int max_int = max_list(1,2,3,4);
    printf("%d\n", max_int);
}

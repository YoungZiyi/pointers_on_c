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
    count--;
    *root = (*root + (number / *root)) / 2;
    if (count) {
        my_sqrt(number, count, root);
    }
    return *root;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000


int read_column_numbers(int columns[], int max);
void rearrange( char* output, char const* input, int n_columns, int const columns[] );


int
main(void) {
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    // read column number
    n_columns = read_column_numbers( columns, MAX_COLS );

    while ( fgets(input, MAX_INPUT, stdin) != NULL ) {
        printf("Original input : %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s\n", output);
    }

    return EXIT_SUCCESS;
}


int
read_column_numbers(int columns[], int max) {
    int num = 0;
    int ch;
    while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0 ) {
        num += 1;
    }

    if (num % 2 != 0) {
        // if num is not a even number, exit with errorno 1
        puts("last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    while ((ch = getchar()) != EOF && ch != '\n') {
        ;
    }

    return num;
}


void
rearrange( char* output, char const* input, int n_columns, int const columns[] ) {
    int col;
    int output_col;
    int len;

    len = strlen(input);
    output_col = 0;

    for ( col = 0; col < n_columns; col+=2 ) {
        int nchars = columns[col + 1] - columns[col] + 1;

        if (columns[col] >= len || output_col == MAX_INPUT - 1) {
            break;
        }

        if (output_col + nchars > MAX_INPUT - 1) {
            nchars = MAX_INPUT - output_col - 1;
        }

        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';
}



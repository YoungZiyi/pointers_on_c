#include <stdio.h>

const int MAX_CHAR = 1000;


void
copy_row(char buff[MAX_CHAR], char row[MAX_CHAR], signed int length) {
    for (int i = 0; i < length; i++) {
        row[i] = buff[i];
    }
}


void
print_row(char row[MAX_CHAR], signed int length) {
    for (int i = 0; i < length; i++) {
        fputc(row[i], stdout);
    }
}


int
main() {
    char row[MAX_CHAR];
    char row_buff[MAX_CHAR];
    signed int char_num = 0;
    char ch;
    int index = 0;
    while ((ch = fgetc(stdin)) != EOF) {
        row_buff[index] = ch;
        index++;
        if (ch == '\n') {
            if (index > char_num) {
                char_num = index;
                copy_row(row_buff, row, char_num);
            }
            index = 0;
        }
    }

    printf("max row length:%d:\n", char_num);
    print_row(row, char_num);
}



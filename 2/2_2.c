#include <stdio.h>
#include <stdlib.h>


void
main(void) {
    int brace_count = 0;
    char ch;
    while ( (ch = fgetc(stdin)) != EOF ) {
        if (ch == '{') {
            brace_count++;
        } else if (ch == '}') {
            brace_count--;
        }
        if (brace_count < 0) {
            break;
        }
    }

    if (brace_count != 0) {
        printf("error");
    } else {
        printf("correct");
    }
}

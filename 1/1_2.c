#include <stdio.h>
#include <stdlib.h>

int
main() {
    int new_line_flag = 1;
    int line_no = 0;
    char ch;
    while (ch = fgetc(stdin)) {
        if (ch == EOF) {
            printf("Bye!");
            return EXIT_SUCCESS;
        }
        if (new_line_flag == 1) {
            printf("%d: ", line_no);
            new_line_flag = 0;
        }
        fputc(ch, stdout);
        if (ch == '\n') {
            line_no++;
            new_line_flag = 1;
        }
    }
}
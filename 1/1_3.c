#include <stdio.h>
#include <stdlib.h>

int
main() {
    signed char checksum = -1;
    char ch;
    while ((ch = fgetc(stdin)) != EOF) {
        fputc(ch, stdout);
        checksum += (signed char)ch;

        if (ch == '\n') {
            if (checksum != -1 && checksum != 9) {
                printf("%d\n", checksum);
            }
            checksum = -1;
            continue;
        }
    }
    return EXIT_SUCCESS;
}

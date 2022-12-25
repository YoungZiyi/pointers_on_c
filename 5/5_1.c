#include <stdio.h>
#include <stdlib.h>

void main() {
    char ch = fgetc(stdin);
    if (ch >= 'A' && ch <= 'Z') {
        ch += 32;
    }
    fputc(ch, stdout);
}

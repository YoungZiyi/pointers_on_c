#include <stdio.h>


int ascii_to_integer(char *string);


int ascii_to_integer(char *string) {
    int i = 0;
    while (*string != '\0') {
        char c = *string++;
        if ((int)c >= 48 && (int)c <= 57) {
            i = i*10 + (int)(c-48);
        } else {
            return 0;
        }
    }
    return i;
}


void main() {
    char *str = "123";
    int i = ascii_to_integer(str);
    printf("%d\n", i);
}

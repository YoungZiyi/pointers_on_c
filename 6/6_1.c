#include <stdio.h>
#include <stdlib.h>


char *find_char(char const *source, char const *chars);


void main() {
    char *source = "asdfzcxv";
    char *chars = "abbbbb";
    char *c = find_char(source, chars);
    printf(">>>>>>>>>>>>>>>>>%c\n", *c);
}


char *find_char(char const *source, char const *chars) {
    if (source == NULL || chars == NULL) {
        return NULL;
    }

    for (char const *index = source; *index != '\0'; index++) {
        for (char const *index2 = chars; *index2 != '\0'; index2++) {
            if (*index == *index2) {
                return (char *)index;
            }
        }
    }
    return NULL;
}

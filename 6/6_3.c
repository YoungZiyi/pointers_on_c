#include <stdio.h>
#include <string.h>


void reverse_string( char *string );
void reverse_string_v2( char *string );


void main() {
    char str[] = "abcdefg";
    printf("%s\n", str);
    reverse_string(str);
    printf("%s\n", str);

    printf("v2:%s\n", str);
    reverse_string_v2(str);
    printf("v2:%s\n", str);
}


void reverse_string( char *string ) {
    if (string == NULL) {
        return;
    }
    int str_len = strlen(string);
    int i, j;
    char c;
    for (i = 0; i < str_len / 2; i++) {
        j = str_len - i -1;
        // printf("%d => %d\n", i, j);
        c = string[i];
        string[i] = string[j];
        string[j] = c;
    }
}


void reverse_string_v2( char *string ) {
    if (string == NULL) {
        return;
    }
    char *last = string;
    while (*last != '\0') {
        last++;
    }
    last--;
    while ( string < last ) {
        char ch = *string;
        *string = *last;
        *last = ch;

        string++;
        last--;
    }
}

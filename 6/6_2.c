#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int del_substr(char *str, char const *substr);


void main() {
    char str[] = "asdfffzcxv";
    char substr[] = "fff";

    int i = del_substr(str, substr);
    printf(">>>>>>>>>>>>>>>>>%s\n", str);
}


int del_substr( char *str, char const *substr ) {
    if (str == NULL || substr == NULL) {
        return 0;
    }
    int str_len = strlen(str);
    int substr_len = strlen(substr);
    if (str_len < substr_len) {
        return 0;
    }

    int i, j, k;
    for ( i = 0; i <= str_len - substr_len; i++) {
        for ( j = i; j < substr_len + i; j++) {
            if ( str[j] != substr[j-i] ) {
                break;
            }
        }

        if ( j == substr_len + i ) {
            // j此时指向str匹配substr之后的一个字符
            for ( k = j; k <= str_len; k++ ) {
                str[k-substr_len] = str[k];
            }
            return 1;
        }
    }
    return 0;
}

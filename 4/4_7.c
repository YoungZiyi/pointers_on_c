#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void deblank(char string[]);


void main() {
    char string[10] = "a  b  cd  ";
    printf("\n=========origin:%s=========\n", string);
    deblank(string);
    printf("\n=========dblank:%s=========\n", string);
}


// most stupid version
void deblank(char string[]) {
    int len = strlen(string);
    char pre_ch, cur_ch, nex_ch;
    for (int i = 1; i < len; i++) {
        pre_ch = string[i-1];
        cur_ch = string[i];
        if (pre_ch == ' ' && cur_ch == ' ') {
            for (int j = i + 1; j <= len; j++) {
                string[j-1] = string[j];
            }
        }
    }
}

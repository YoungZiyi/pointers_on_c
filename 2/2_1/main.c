#include <stdio.h>
#include "increment.c"
#include "negate.c"

void
main(void) {
    int r1, r2, r3, r4, r5, r6;
    r1 = increment(10);
    r2 = increment(0);
    r3 = increment(-10);
    
    r4 = negate(10);
    r5 = negate(0);
    r6 = negate(-10);

    printf("increment(10) -> %d; negate(10) -> %d\n", r1, r4);
    printf("increment(0) -> %d; negate(0) -> %d\n", r2, r5);
    printf("increment(-10) -> %d; negate(-10) -> %d\n", r3, r6);
}
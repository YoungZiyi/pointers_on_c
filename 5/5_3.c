/**
 * 请编写函数
 * unsigned int reverse_bits(unsigned int value);
 * 这个函数的返回值是把value的二进制位模式从左到右变换一下后的值，例如，
 * 在32位机器上，25这个值包含下列各个位：
 * 00000000000000000000000000011001
 * 函数的返回值应该是2550136832，它的二进制位模式是：
 * 10011000000000000000000000000000
 * 编写函数时要注意不要让它依赖于你的机器上整型值的长度。
 */

#include<stdio.h>


unsigned int reverse_bits(unsigned int value);
void bin(unsigned n);


void main() {
    unsigned integer = 25;
    printf(">%u\n", integer);
    bin(integer);
    integer = reverse_bits(integer);
    printf("\n>%u\n", integer);
    bin(integer);
}


unsigned int reverse_bits(unsigned int value) {
    unsigned int answer = 0;
    unsigned int i;
    for (i = 1; i != 0; i <<= 1) {
        answer <<= 1;
        if (value & 1) {
            answer |= 1;
        }
        value >>= 1;
    }
    return answer;
}


// print number in binary mode
void bin(unsigned n) {
    unsigned i;
    // brilliant!
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

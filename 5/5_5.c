/**
 * 编写一个函数，把一个给定的值存储到一个整数中指定的几个位。原型如下：
 * int store_bit_field(int original_value, 
 *                     int value_to_store, 
 *                     unsigned starting_bit, 
 *                     unsigned ending_bit);
 * 假定整数中的位从右到左进行编号。因此，起始位的位置不会小于结束位的位置。
 * 为了更清楚地说明，函数应该返回下列值：
 * 表略
 * 
 * 注意！步骤1有错误，最后的掩码应该是0011111000000000，书上少了一个0
 */

#include<stdio.h>


int store_bit_field(int original_value, 
                    int value_to_store, 
                    unsigned starting_bit, 
                    unsigned ending_bit);
void bin(unsigned n);


void main() {
    // int original_value = 0x0;
    // int value_to_store = 0x1;
    // unsigned starting_bit = 4;
    // unsigned ending_bit = 4;

    // int original_value = 0xffff;
    // int value_to_store = 0x123;
    // unsigned starting_bit = 15;
    // unsigned ending_bit = 4;

    int original_value = 0xffff;
    int value_to_store = 0x123;
    unsigned starting_bit = 13;
    unsigned ending_bit = 9;

    unsigned short ret = store_bit_field(original_value, value_to_store, starting_bit, ending_bit);
    printf("%x\n", ret);
    bin(ret);
}


int store_bit_field(int original_value, 
                    int value_to_store, 
                    unsigned starting_bit, 
                    unsigned ending_bit) {

    // 步骤一：创建一个掩码（mask），其中需要存储的位置设置位1
    unsigned short mask = 0;
    for (unsigned i = starting_bit; i >= ending_bit; i--) {
        unsigned pos = 1<<i;
        mask |= pos;
    }
    // 步骤二：用掩码的反码对原值执行AND操作
    original_value = (unsigned short)original_value & (unsigned short)~mask;
    // 步骤三：将新值左移，使其与那几个需要存储的位置对其
    value_to_store <<= ending_bit;
    // 步骤四：把左移后的新值与掩码进行AND操作，确保那几个需要存储的位置之外的其余位置置为0
    value_to_store = (unsigned short)value_to_store & (unsigned short)mask;
    // 步骤五：把上一步结果与原值进行OR操作并返回
    return (unsigned short)value_to_store | (unsigned short)original_value;
}


// print number in binary mode
void bin(unsigned n) {
    unsigned i;
    // brilliant!
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}

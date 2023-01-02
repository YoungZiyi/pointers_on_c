/**
 * 编写一组函数，实现位数组。函数原型如下：
 * void set_bit(char bit_array[], unsigned bit_number);
 * void clear_bit(char bit_array[], unsigned bit_number);
 * void assign_bit(char bit_array[], unsigned bit_number, int value);
 * int test_bit(char bit_array[], unsigned bit_number);
 * 
 * 每个函数的第1个参数是个字符数组，用于实际存储所有的位。
 * 第2个参数用于标识需要访问的位。函数的调用者必须确保这个值不要太大，
 * 以免超过数组的边界。
 * 
 * 第一个函数把指定的位设置为1
 * 第二个函数把指定的位清零
 * 第三个函数把指定的位设置为value(0或1)
 * 第四个函数测试指定位置是否为1，如果是1，返回真，否则返回假
 */

#include<stdio.h>


void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);


void main() {
    // 这个题目有点看不懂，瞎jb写的
    char bit_array[10] = {
        '0', '1', '0', '0', '0', '0', '0', '0', '0', '0'
    };
    unsigned bit_number = 2;
    
    set_bit(bit_array, bit_number);
    clear_bit(bit_array, bit_number);
    assign_bit(bit_array, bit_number, 0);
    printf("%d", test_bit(bit_array, bit_number));
}


void set_bit(char bit_array[], unsigned bit_number) {
    bit_array[bit_number] = '1';
}


void clear_bit(char bit_array[], unsigned bit_number) {
    bit_array[bit_number] = '0';
}


void assign_bit(char bit_array[], unsigned bit_number, int value) {
    bit_array[bit_number] = value==0 ? '0' : '1';
}


int test_bit(char bit_array[], unsigned bit_number) {
    if (bit_array[bit_number] == '0') {
        return 0;
    }
    return 1;
}

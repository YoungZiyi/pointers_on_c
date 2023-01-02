/**
 * 等边三角形的3条边长度都相等，但等腰三角形只有两条边相等，如果三角形
 * 三条边都不相等，就称为不等边三角形，编写一个程序，提示用户输入3个数，
 * 分别标识三角形的3条边长度，然后由程序判断它是什么类型的三角形。
 * 提示：除了边的长度是否相等，程序是否还需要考虑一些其他的东西？
 * 
 */

#include <stdio.h>
#include <stdlib.h>


void check_triangle(float line1, float line2, float line3);


void
main()
{
    float line1, line2, line3;
    printf("Please input line1:");
    scanf("%f", &line1);
    printf("Please input line2:");
    scanf("%f", &line2);
    printf("Please input line3:");
    scanf("%f", &line3);
    printf("\n");
    printf("line1=>%f\n", line1);
    printf("line2=>%f\n", line2);
    printf("line3=>%f\n", line3);

    check_triangle(line1, line2, line3);

}


void
check_triangle(float line1, float line2, float line3) {
    if (line1 < 0 || line2 < 0 || line3 < 0 || 
        (line1 + line2) < line3 || 
        (line1 + line3) < line2 || 
        (line2 + line3) < line1 ) {
        // 需要判断三条边是否能组成一个三角形
        printf("error input\n");
        exit(EXIT_SUCCESS);
    }

    if (line1 == line2 && line1 == line3) {
        // 等边三角形
        printf("equilateral triangle\n");
        exit(EXIT_SUCCESS);
    }

    if (line1 == line2 || line1 == line3 || line2 == line3) {
        // 等腰三角形
        printf("equicrural triangle\n");
        exit(EXIT_SUCCESS);
    }

    // 不等边三角形
    printf("non-equilateral triangle\n");
    exit(EXIT_SUCCESS);
}

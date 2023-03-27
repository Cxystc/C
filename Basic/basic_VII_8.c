#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    switch (x)
    { // 请在此处设置断点，单步调试本程序，观察将运行哪些语句
    case 4:
        printf("Shenzhen\n");
    case 3:
        printf("Guangzhou\n");
    case 2:
        printf("Beijing\n");
    case 1:
        printf("Shanghai\n");
    default: printf("Xiaojiujiu");
    }
}
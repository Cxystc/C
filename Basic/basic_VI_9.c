#include <stdio.h>
#include <string.h>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    { //循环
        if (i % 2 == 0)
        { //判断是否是奇数
            sum -= i;
        }
        else
        {
            sum += i;
        }
    }
    printf("sum = %d\n ", sum);
}

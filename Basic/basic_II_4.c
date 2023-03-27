//计算累加100
#include <stdio.h>
#include <math.h>
#include <string.h>
int main ()
{
    int sum = 0 ;
    int i  = 1 ;
    while (i<= 100)
    {   static int j = 0;
        j ++ ;//局部静态变量
        sum = sum + i ; 
        i ++; 
        printf("%d\n",i);
        printf("%d\n",j);//输出100 没用重新定义

    }
    printf("The sum of 1 to 100 is %d\n",sum);
    return 0;
}
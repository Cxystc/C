#include <stdio.h>

int main()
{
    long long sum = 0;
    long long b [20] = {0}; 
    long long s = 1 ;//要用长整形
    for (int i = 1; i <= 20; i++)//循环阶乘
    { 
    s *= i ; 
    sum += s ; 
    b [i-1] = sum ; 
    }
    int n;
    printf("please input a number:\n");
    scanf("%d",&n);
    printf("%d\n",b[n-1]);
}

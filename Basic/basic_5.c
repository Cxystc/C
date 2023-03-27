//function
#include <stdio.h> 
#include <string.h>

int max(int a, int b);//声明
int max(int a, int b)//定义
{
    int z ;
    z = a > b ? a : b ;// z = a 如果a>b ,否则z = b
    printf("%d\n",z);
    return z;
}

//函数的调用：函数名（实参）
//实参可以是常量变量或者表达式，实参和形参的数据类型要一样
//实参的值不会因为形参的改变而改变
void main()
{
    max(10,20);
    char a[]  = "ABCDEF";
    char b[] = {'A','B','C','D','E','F'};

    printf("%d\n",strlen(a));//208
    printf("%d\n",strlen(b));//14 
    puts(a);
    puts(b);
}

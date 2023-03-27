//指针数组
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *p[] = {"shining", "sunny", "windy"};//这是一个指针数组
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", p[i]);
        printf("%s\n",*(p+ i));//都是表示地址
    }
    char **pointer = p;
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n",*pointer[i]);
        printf("%d\n",1+1);
    }
}
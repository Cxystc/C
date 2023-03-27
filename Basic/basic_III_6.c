#include <string.h>
#include <stdio.h>
//用指针数组完成类似python列表的操作
int main ()
{
    char *p[] = {"This is a list like python list","But this list is wort based on c & cpp"};//这是一个指针数组
    for (int i = 0 ; i < 2 ; i++)
    {
        printf("%s",p[i]);
    }
    return 0;
}
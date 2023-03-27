#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int getdate(time_t timep) //把秒数变成日期的函数
{
    struct tm *p;
    p = gmtime(&timep);
    int time = p->tm_mday + (1 + p->tm_mon) * 100;
    return time;
}

int main()
{

    for (int i = 0; i < 100; i++)
    {
        time_t timep;
        time(&timep); //秒数
        timep -= 86400 * i;
        printf("%d\n", getdate(timep));
    }
    return 0;
}

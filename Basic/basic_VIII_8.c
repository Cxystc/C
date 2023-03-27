#include <stdio.h>
int adding(int max);
int adding(int max)
{
    static int i = 1;
    static int sum = 0;
    sum += i;
    printf("%d ", sum);
    if (i == max)
        return sum;
    i++;
    adding(max);
}
int main()
{
    adding(30);
}
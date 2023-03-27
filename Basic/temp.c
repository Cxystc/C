#include <string.h>
#include <stdio.h>

char *point(char *p)
{
    return p += 3;
}
int main()
{
    char b[4] = {'a', 'b', 'c', 'd'};
    char *pt = b;
    pt = point(pt);
    printf("%c\n", *pt);
    return 0;
}
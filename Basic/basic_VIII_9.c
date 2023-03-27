#include <stdio.h>
#include <string.h>

void  all_strip(char *a)
{
    int an = 0;
    while (a[an] != '\0')
    {
        an++;
    }
    for (int i = 0; i < an; i++)
    {
        if (a[i] == ' ' || a[i] == '_')
        {
            for (int j = i; j < an; j++)
            {
                a[j] = a[j + 1];
            }
            an--;
            a[an-1] = '\0';
            i--; //注意这里因为发生了位移所以这个i已经不一样了，要减去一下；
        }
    }
}
int main()
{
    char test[19] = "a b dfaegd _ dagal";
    printf("%s\n",test);
    all_strip(test);
    printf("%s\n",test);
}
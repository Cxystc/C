
#include <stdio.h>
int change(int *p)
{

    int i, m, j;
        for (i = 0; i < 10; i++)
        {
            if (*(p + i) == 0)
            {
                int temp = *(p + i);
                for (j = i + 1; j < 10; j++)
                {
                    *(p + j - 1) = *(p + j);
                }
                *(p+j-1) = temp;//最后一个总是0
            }
        }
        for (i = 0; i < 10; i++)
        {
            printf("%2d", *(p + i));
        }
    return 0;
}

int main(void)
{
    int a[10];
    int i;
    printf("Please input:");
    for (i = 0; i < 10; i++)
    {
        scanf("%d ", &a[i]);
    }

    printf("a[10]=");
    for (i = 0; i < 10; i++)
    {
        printf("%2d", a[i]);
    }
    printf("\n");

    int *p;
    p = a;
    printf("after:");
    change(p);
}

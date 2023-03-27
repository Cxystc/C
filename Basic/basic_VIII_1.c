#include <stdio.h>

int main()
{
    float sum = 1;
    int a[4][6] = {{0.2, 0.3}, {}, {0.888, 0.864, 0.93714}, {0.3415, 0.342195}};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (a[i][j] != 0)
            {
                printf("%f row:%d   colum:%d\n", a[i][j], i, j);
                sum *= a[i][j];
            }
        }
    }
    printf("sum of all : %f\n", sum);

    for (int i = 0; i < 4; i++)
    {
        float s = 1;
        for (int j = 0; j < 6; j++)
        {
            if (a[i][j] != 0)
            {
                s *= a[i][j];
            }
        }
        printf("sum of row :%f\n", s);
    }

    for (int i = 0; i < 6; i++)
    {
        float s = 1;
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] != 0)
            {
                s *= a[j][i];
            }
        }
        printf("sum of colum :%f\n", s);
    }
}
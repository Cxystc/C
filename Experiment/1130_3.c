#include <stdio.h>

int main()
{
    int a[3][4][5];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int z = 0; z < 5; z++)
            {
                a[i][j][z] = 20 * i + 5 * j + z + 1;
            }
        }
    }

    int *p1 = (int *)a;
    int **p2 = (int **)a;
    int(*p3)[5] = (int **)a;//一维数组的指针
    int *p4 [4];//指针的数组
    for (int i = 0; i < 3; i++)
    {   


        
        for (int j = 0; j < 4; j++)
        {
            p4[j] = &a[i][j][0]; 
            for (int z = 0; z < 5; z++)
            {
                printf("%d ", *((int *)p1 + 20 * i + 5 * j + z));
                printf("%d ", *((int *)p2 + 20 * i + 5 * j + z));//看作一个大的矩阵处理
                printf("%d ", *((int *)p3 + 20 * i + 5 * j + z));
                printf("%d ",*p4[j]++);
            }
            printf("\n");
        }
    }
}
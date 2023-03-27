#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[4][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int *p1 = (int *)a;   //指针
    int **p2 = (int **)a; //双重指针，指向指针的指针 *p 即使一个之其中一行
    int(*p3)[5] = a;      // int[5]类型数组的指针
    int *p4[4];       //指针数组
    for (int i = 0; i < 4; i++)
    {   
        p4[i] = &a[i][0];
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", *(p1 + 5 * i + j));        //看作一个大矩阵处理
            printf("%d ", *((int *)p2 + 5 * i + j)); // p2是int ** 类型，先转化为 (int * 类型)
            printf("%d ", *(*(p3 + i) + j));         //*(p3+i)是一个int[5]类型
            printf("%d ", *p4[i]++);             // p3[i]是一个指向[4] 的指针
        }
        printf("\n");
    }
}

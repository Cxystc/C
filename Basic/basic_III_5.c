//用指针方法编写一个程序，输入 3 个整数，将它们按由小到大的顺序输出
#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int a[] = {2, 4, 5, 34, 8, 90, 6, 3, 5, 24, 88, 45, 26, 87};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int *pp = b;
    int *p = a;
    int sortting(int *, int);
    int len = sizeof(a) / sizeof(int);
    printf("\nSorted array 1 : \n");
    sortting(p, len);
    printf("\nSorted array 2\n");
    sortting(pp, len-2);
}
int sortting(int *array, int len) //冒泡法实现排序，实际上是沉底法
{
    int flag = 0;
    for (int i = 0; i < len - 1; i++)
    {   
        if (i != 0){
            if (flag == 0 )
            printf("You have give me a sorted array\n");
            break;
        }
        printf("%d\n",i);
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (*(array + j) > *(array + j + 1))
            {
                flag = 1 ; 
                int temp;
                temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
                flag = 1 ;
            }        
        }    
    }
    
    for (int i = 0; i < len - 2; i++)
    {
        printf("%d ", *(array + i));
    }
}
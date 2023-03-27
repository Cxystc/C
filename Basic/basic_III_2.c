// bubble sort
#include <string.h>
#include <stdio.h>

int main()
{
    int sortting(int[], int), len;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 9, 7, 6, 2};
    len = sizeof(arr) / sizeof(*arr);
    sortting(arr, len);
    //按顺序打印数列
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    char content[] = {"Finished"};
    printf("%s\n", content);
}

int sortting(int arr[], int len)
{
    int flag = 0;
    int i, j, temp; //temp用于做交换
    for (i =0 ; i < len-1 ; i ++)
        for (j = 0 ; j < len -1 -i; j++)//没有理解循环的原理所以才会写错
            if (arr[j] > arr [j + 1])
            {
                temp = arr [j];
                arr [j] = arr [j + 1]; 
                arr [j + 1] = temp;
                flag = 1;
            }
    
    //得到一个排好序的数列
}
#include <stdio.h>
#include <stdlib.h>

int sift(int *list, int low, int high);

int sift(int *list, int low, int high)
{
    int temp = list[low];
    int i = low;
    int j = 2 * i + 1;
    //初始化

    while (j <= high)
    {
        if (j + 1 <= high && list[j + 1] > list[j])
        {
            j += 1;
        }//选择大的子元素

        if (temp < list[j])
        {
            list[i] = list[j];
            i = j;
            j = 2 * i + 1;
        }//如果不够格，就把下一个移上去，然后继续向下寻找

        else
        {
            break;//够格的话就要跳出去
        }
    }
    list[i] = temp;//不论是else中break还是while不符合跳出，最后都要把temp放回去
    return 0;
}

int heap_sort(int *list, int n);
int heap_sort(int *list, int n)
{
    //建立堆:list数组；n是数组长度
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        sift(list, i, n - 1);
    }
    //逐个出数
    for (int i = n - 1; i >= 0; i--)
    {
        int tmp = list[0];
        list[0] = list[i];
        list[i] = tmp;//把最后堆的最后一个数提上来，堆顶元素放下去，然后做向下调整
        sift(list,0,i-1);//注意这里是i-1，因为最后一个元素刚刚是堆顶拿下来的，不是堆里的元素
    }
    return 0;
}

int main()
{
    int a[10] = {9, 8, 7, 658463, 73626737, 3, 2, 1,1,78316};
    int j = 0;
    while (a[j] != 0)
    {
        j++;
    }
    for (int i = 0; i < j; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    heap_sort(a, j);
    for (int i = 0; i < j; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
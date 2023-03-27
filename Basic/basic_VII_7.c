//查找算法
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int binary_research(int *, int,int );
    int a[19] = { 1,2, 3, 4,  5, 6, 7, 8, 9,10, 11, 12, 13,14,15, 16, 17, 18, 19 };
    int index = binary_research(a,5,119);


}
int binary_research(int *li, int val,int LEN )
{
    int left = 0;
    int right = LEN - 1;
    while (left <= right)
    {
        int mid = (left + right); // 2 ;
            if (li[mid] == val)
        {
            printf("I have found the index : %d\n",mid);
            return mid;
        }
        else if (li[mid] > val)
        { //带查找的值在mid左侧
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    printf("\"%d\" does not exist in the list\n",val);
    return NULL;
}

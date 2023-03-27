//选择排序
#include<stdio.h>

    int main()
{
    int selecting_sort(int * , int );
    int list[20] = {5, 4, 31, 88, 3, 6, 3, 14, 6, 9};
    selecting_sort(list,10);
    
}
int selecting_sort(int *list, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i+1; j < len; j++)
        {
            //易错点，每次j都是无序区的第一个数
            if(list[j] < list[min]){
                min = j ;
            }
        }
        int temp = list[i] ;
        list[i] = list[min];
        list[min] = temp;//写每一行代码都要小心
        for (int z = 0 ; z < len ; z++){
            printf("%d ",list[z]);
        }
        printf("\n");

    }
    return 0 ; 
}
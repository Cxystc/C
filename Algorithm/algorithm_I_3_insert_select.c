//插入排序
#include<stdio.h>

int main()
{
    int insert_sort (int *,int);
    int list[] = {9,8,7,6,5,4,3,2,1,0};
    insert_sort(list,10);
}
int insert_sort(int *list, int len)
{
    for (int j = 0 ; j < len-1 ; j++){
        int i = j + 1; 
        int temp = list[i];
        while(j >= 0 && temp < list[j] )//i比j小的时候就要向左移动，所以不要跳出
        {
            list[j+1] = list[j];
            j = j -1 ; 
        }
        list[j+1] = temp;
        for (int i = 0 ; i < len ; i++){
            printf("%d ",list[i]);
        }
        printf("\n");
    }
}
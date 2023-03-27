#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b);
int sorting(int * array,int n );

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int sorting(int * array,int n )
{
        int row, column,_;
        printf("Please input the r & c:\n");
        scanf("%d %d", &row, &column);
        int sum = row * column + 2 ;
        array = malloc(sizeof(int) * sum);
        int num[sum]; //数组的前两个位置用来放参数
        num[0] = row;
        num[1] = column;
        // array = (int)malloc(sizeof(int) * sum);
        
        for (int i = 2; i < sum; i++)
        {
            scanf("%d", &num[i]);
        }
        qsort(num + 2, row * column, sizeof(int), cmp);//排序
        
        for (int i = 0 ; i < sum ; i ++){
            array[_] = num[i]; 
            _ += 1; 
        }//一维数组放到二维数组里

        return array; 
}//返回一个二维数组

    int main()
    {   
        int n = 0;
        scanf("%d", &n); //数组数
        int array[] = {0}; //声明储存数组
        for (int i = 0; i < n; i++)
        {
            sorting(array,n);//获取数据
        }

        int i = 0 ;
        while (1)//输出数据
        {   
            int row = array[i];
            int column = array[i+1];
            if (row == 0 ) break;
            int sum = column * row +2 ; 
            for ( int j = i+2 ; j < sum + i ; j ++ ){
                printf("%d ",array[j]);
                if ((j-1)%column == 0){
                    printf("\n");
                }
            }
            i += sum ; 

        }
    return 0;
    }

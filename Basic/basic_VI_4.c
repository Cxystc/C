#include <stdio.h>
#include <stdlib.h>

//确实没有必要先变成2维，直接一维输入，一维输出就好了

int main()
{
    int Times;
    scanf("%d", &Times);
    int size[Times][2]; //用来储存参数的二维数组
    int *(ArrayList[Times])[10][10]; //指针数组用来存储每一个矩阵

    for (int i = 0; i < Times; i++)
    {   
        int n = size[i][1];
        int m = size[i][2];
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int _;
                scanf("%d", &_);
                *(ArrayList[i])[n][m] = (int)malloc(sizeof(int));
                *(ArrayList[i])[n][m] = _;
            }
            printf("\n");
        }//获取每一个数组的数据


    } //上面是获取模块

    //下面是重整和排序模块
    for (int _ = 0; _ < Times; _++)
    {
        int n = size [_][1];
        int m = size [_][2];
        int b[n * m]; // b是重整后的

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                b[i * j + j + 1] = *(ArrayList[_])[i][j];
            }
        }
        //重整

        for (int i = 0; i < m * n; i++)
        {
            for (int j = 0; j < m * n - i - 1; j++)
            {
                if (b[j] > b[j + 1])
                {
                    int temp = b[j];
                    b[j] = b[j + 1];
                    b[j + 1] = temp;
                }
            }
        } //冒泡法排序

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                *(ArrayList[_])[i][j] = b[i * j + j + 1];
            } //给他怼回去
        }
    }
    //得到一个重整排序完毕的arrayList;

    for (int _ = 0; _ < Times; _++)
    {   
        int n = size[Times][1];
        int m = size[Times][2];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", *(ArrayList[_])[i][j]);
            }
            printf("\n");
        } //打印出来完事
    }
}
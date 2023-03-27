#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int sum = 0;          //空的总数
    int s = 0;            //一个空的数
    int row = 0, col = 0; //一个空的参数
    scanf("%d %d", &n, &m);
    fflush(stdin);
    char win[n*m];
    //方法1
    // for (int i = 0; i < n; i++)
    // {   
    //     fflush(stdin);
    //     for (int j = 0; j < m; j++)
    //     {
    //         scanf("%c", &win[i * m + j]);
    //         if (win[i *m + j] == '\n')
    //             j--;
    //         // if (win[i * n + j] == ' ')
    //         //     sum++;
    //     }
    // }   

    // 方法2
    // for (int i = 0; i < n * m; i++)
    // {
    //     win[i] = getchar();
    //     if (win[i] == '\n')
    //      i--;
    // }

    // 方法3
    for (int i = 0 ; i < n ; i ++){
        scanf("%[^\n]",win+i*m);
        fflush(stdin);
    }

    // // 打印
    // printf("\n");
    // for (int i = 0 ; i < n ; i++){
    //     for (int j = 0 ; j < m ; j ++){
    //         printf("%c",win[i*m + j]);
    //     }
    //     printf("\n");
    // }

    //得到空的总数
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != 0 && j != 0 && i != n - 1 && j != m - 1)
            {
                if (win[i * m + j] == ' ')
                {
                    sum++;
                }
            }
        }
    }

    if (sum == 0)
    {
        printf("0");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (i != 0 && j != 0 && i != n - 1 && j != m - 1)
            {
                if (win[m * i + j] == ' ')
                {
                    flag = 1;
                    row = 1;
                    col = 1;
                    int I = m * i + j;
                    int a = 0, b = 0;
                    while (win[I + a * m] == ' ')
                    {
                        a++;
                    }
                    while (win[I + b] == ' ')
                    {
                        b++;
                    }
                    s = a * b;
                    break;
                }
            }
        }
        if (flag == 1)
            break;
    }
    int number = sum / s;
    printf("%d\n", number);
    return 0;
}

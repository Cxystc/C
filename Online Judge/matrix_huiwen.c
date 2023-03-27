#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reversing(char *list, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            char temp = list[j];
            list[j] = list[j + 1];
            list[j + 1] = temp;
        }
    }
    char temp = list[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        list[i] = list[i - 1];
    }
    list[0] = temp;
} //倒序

//获取回环数组
void list_getting(char **list, char *circle, int n, int i, int LEN)
{ //原字符数组，单行的字符数组（一维的）
    // printf("\nLEN: %d\n", LEN);
    int un = 0; //作为circle的下标
    //当n = 3 时 i = 0 时
    for (int j = i; j < n - i - 1; j++, un++)
    {
        circle[un] = *((char *)list + (n - (i * 2) - 1) * i + j);
    }
    for (int j = i; j < n - i - 1; j++, un++)
    {
        circle[un] = *((char *)list + (n - (i * 2)) * j + (n - i - 1));
    }
    for (int j = n - 1 - i; j > 0; j--, un++)
    {
        circle[un] = *((char *)list + (n - (i * 2)) * (n - 1 - i) + j);
    }
    for (int j = n - 1 - i; j > 0; j--, un++)
    {
        circle[un] = *((char *)list + (n - (i * 2)) * j + i);
    }
}

int main()
{
    int N = 0;
    // printf("Please input the times : \n");
    scanf("%d", &N);
    printf("\n");
    for (int k = 0; k < N; k++)
    {
        // printf("\nPlease input the n : ");
        int n;
        scanf("%d", &n);
        char matrix[n][n];
        fflush(stdin);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = getchar();
            }
            fflush(stdin);
        }

        int flag = 1;                   //默认是回文矩阵
        for (int i = 0; i < n / 2; i++) //只要有一个不是，全都不是
        {
            //计算当前环的长度
            int LEN = (n - (i * 2) - 1) * 4;
            char circle[LEN];
            char b[LEN];
            list_getting((char **)matrix, circle, n, i, LEN);
            strcpy(b, circle);
            reversing(b, LEN); // b就是返序后的circle
            printf("\n");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%c", matrix[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            //打印一圈
            for (int i = 0; i < LEN; i++)
            {
                printf("%c ", circle[i]);
            }
            printf("\n");
            //打印反向的函数
            for (int i = 0; i < LEN; i++)
            {
                printf("%c ", b[i]);
            }

            for (int i = 0; i < LEN; i++)
            {
                if (circle[i] != b[i])
                {
                    flag = 0;
                    break;
                } //不成立
            }
        }
        if (flag == 0)
            printf("\nNo\n");
        if (flag == 1)
            printf("\nYes\n");
    }
}
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int chang=1;
int kuan=1;
char juxing[5005][5005];
void serach1(int i,int j);
void serach2(int i,int j);
int main()
{
    int row, column;
    scanf("%d%d", &row, &column);
    int sum = 0;
    int i, j;
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= column; j++)
        {
            scanf("%c", &juxing[i][j]);
            if (juxing[i][j] == '\n')
            {
                j = 1;
            }
            if (juxing[i][j] == ' ')
            {
                sum++;
            }
        }
    }
    if (sum == 0)
    {
        printf("0");
        return 0;
    }
    else
    {
        int flag = 0;
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= column; j++)
            {
                if (juxing[i][j] == ' ')
                {
                    serach1(i, j);
                    serach2(i, j);
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
        printf("%d", sum / (chang * kuan));
        return 0;
    }
}
void serach1(int i, int j)
{
    if (juxing[i][j + 1] == ' ')
    {
        chang++;
        serach1(i, j + 1);
    }
}
void serach2(int i, int j)
{
    if (juxing[i + 1][j] == ' ')
    {
        kuan++;
        serach2(i + 1, j);
    }
}
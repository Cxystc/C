#include <stdio.h>

int main()
{
    char a[8][8] = {' '};
    char b[8][8] = {' '};
    char c[8][16] = {0};
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            a[i][j] = ' ';
            if (i == 0 || j == 0 || i == 7 || j == 7 || i == 3)
            {
                a[i][j] = '*';
            }
            a[0][0] = ' ';
            a[0][7] = ' ';
            a[7][0] = ' ';
            a[3][0] = ' ';
            a[3][7] = ' ';
            a[7][0] = ' ';
            a[7][7] = ' ';
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            b[i][j] = ' ';
            if (i == 0 || j == 0 || i == 7 || j == 7 || i == 3)
            {
                b[i][j] = '*';
            }
            b[0][0] = ' ';
            b[0][7] = ' ';
            b[7][0] = ' ';
            b[3][0] = ' ';
            b[3][7] = ' ';
            b[7][0] = ' ';
            b[7][7] = ' ';
        }
    } //初始化图案 //初始化图案

    int nm;
    scanf("%d", &nm);
    int n = nm / 10;
    int m = nm % 10;

    switch (n)
    {
    case 0:
        for (int i = 1; i < 7; i++)
        {
            a[3][i] = ' ';
        }
        break;
    case 1:
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (j == 7)
                {
                    a[i][j] = '*';
                }
                else
                {
                    a[i][j] = ' ';
                }
            }
        }
        break;
    case 2:
        for (int i = 1; i < 3; i++)
        {
            a[i][0] = ' ';
        }
        for (int i = 4; i < 7; i++)
        {
            a[i][7] = ' ';
        }
        break;
    case 3:
        for (int i = 0; i < 7; i++)
        {
            a[i][0] = ' ';
        }
        break;
    case 4:
        for (int i = 0; i < 7; i++)
        {
            a[0][i] = ' ';
            a[7][i] = ' ';
        }
        for (int i = 4; i < 7; i++)
        {
            a[i][0] = ' ';
        }
        a[0][0] = '*';
        a[0][7] = '*';
        a[7][7] = '*';
        break;
    case 5:
        for (int i = 1; i < 3; i++)
        {
            a[i][7] = ' ';
        }
        for (int i = 4; i < 7; i++)
        {
            a[i][0] = ' ';
        }
        break;
    case 6:
        for (int i = 0; i < 3; i++)
        {
            a[i][7] = ' ';
        }
        break;
    case 7:
        for (int i = 0; i < 8; i++)
        {
            a[i][0] = ' ';
        }
        for (int i = 0; i < 8; i++)
        {
            a[3][i] = ' ';
            a[7][i] = ' ';
        }
        a[3][7] = '*';
        a[7][7] = '*';
        break;
    case 8:
        break;
    case 9:
        for (int i = 4; i < 7; i++)
        {
            a[i][0] = ' ';
        }
    default:
        break;
    }
    //改变a
    switch (m)
    {
    case 0:
        for (int i = 1; i < 7; i++)
        {
            b[3][i] = ' ';
        }
        break;
    case 1:
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (j == 7)
                {
                    b[i][j] = '*';
                }
                else
                {
                    b[i][j] = ' ';
                }
            }
        }
        break;
    case 2:
        for (int i = 1; i < 3; i++)
        {
            b[i][0] = ' ';
        }
        for (int i = 4; i < 7; i++)
        {
            b[i][7] = ' ';
        }
        break;
    case 3:
        for (int i = 0; i < 7; i++)
        {
            b[i][0] = ' ';
        }
        break;
    case 4:
        for (int i = 0; i < 7; i++)
        {
            b[0][i] = ' ';
            b[7][i] = ' ';
        }
        for (int i = 4; i < 7; i++)
        {
            b[i][0] = ' ';
        }
        b[0][0] = '*';
        b[0][7] = '*';
        b[7][7] = '*';
        break;
    case 5:
        for (int i = 1; i < 3; i++)
        {
            b[i][7] = ' ';
        }
        for (int i = 4; i < 7; i++)
        {
            b[i][0] = ' ';
        }
        break;
    case 6:
        for (int i = 0; i < 3; i++)
        {
            b[i][7] = ' ';
        }
        break;
    case 7:
        for (int i = 0; i < 8; i++)
        {
            b[i][0] = ' ';
        }
        for (int i = 0; i < 8; i++)
        {
            b[3][i] = ' ';
            b[7][i] = ' ';
        }
        b[3][7] = '*';
        b[7][7] = '*';
        break;
    case 8:
        break;
    case 9:
        for (int i = 4; i < 7; i++)
        {
            b[i][0] = ' ';
        }
    default:
        break;
    }
    //改变b

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (j < 8)
            {
                c[i][j] = a[i][j];
            }
            else
            {
                c[i][j] = b[i][j - 8];
            }
        }
    }//改变c
    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        printf("\n");
        for (int j = 0; j < 16; j++)
        {
            printf("%c", c[i][j]);
        }
    }
}

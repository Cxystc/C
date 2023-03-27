#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// int CTRL(char *str)
// {
//     char a[5] = "CTRL";
//     for (int i = 0; i < strlen(str); i++)
//     {
//         if (str[i] == 'C')
//         {
//             if (i != 0)
//             {
//                 if (str[i - 1] == 'N')
//                     continue;
//             }
//             for (int j = 0; j < 4; j++)
//             {
//                 if (str[i + j] != a[j])
//                     flag1 = 0;
//             }
//             flag1 = 1;
//         }
//     }
//     return 0; // 0就是没找到
// }
// int UNCTRL(char *str)
// {
//     for (int i = 0; i < strlen(str); i++)
//     {
//         if (str[i] == 'U')
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 if (str[i + j] != b[j])
//                     return 0;
//             }
//             return 1;
//         }
//     }
//     return 0; // 0就是没找到
// }
int main()
{
    int flag1 = 0; // 用来保存ctrl的状态
    int flag2 = 0; // 用来保存cv的状态
    int N;
    scanf("%d", &N);
    fflush(stdin);
    char str[100000] = {0};
    char resource[100] = {0};
    char str_valid[1000] = {0};
    int v = 0;
    for (int i = 0; i < N; i++)
    { // 获取字符串
        gets(resource);
        if (i == 0)
        {
            strcpy(str, resource);
        }
        else
        {
            char kong[2] = {' '};
            strcat(str, resource);
            strcat(str, kong);
        }
    }
    char a[5] = "CTRL";
    char b[7] = "UNCTRL";
    for (int i = 0; i < strlen(str); i++)
    {
        int j;
        if (str[i] == 'C' && (flag1 != 1))
        {
            if (i != 0)
            {
                if (str[i - 1] == 'N')
                    continue;
            }
            for (j = 0; j < 4; j++)
            {
                if (str[i + j] != a[j])
                {
                    continue;
                }
            }
            i = i + j - 1; // 把循环变到ctrl后面
            flag1 = 1;
            continue;
        }

        if (flag1 == 1)
            str_valid[v++] = str[i];

        if (str[i] == 'U')
        {
            for (j = 0; j < 6; j++)
            {
                if (str[i + j] != b[j])
                {
                    continue;
                }
            }
            i = i + j - 1; // 把循环变到ctrl后面
            flag1 = 0;
            continue;
        }
    }

    for (int i = 0; i < strlen(str_valid); i++)
    {
        if (i == 0)
        {
            if (str_valid[i] == 'C' && str_valid[i + 1] == ' ')
            {
                flag2 = 1;
                continue;
            }
        }
        else
        {

            if (str_valid[i] == 'C' && str_valid[i + 1] == ' ' && str_valid[i - 1] == ' ')
            {
                flag2 = 1;
                continue;
            }
            if (flag2 == 1 && str_valid[i] == 'V' && str_valid[i + 1] == ' ' && str_valid[i - 1] == ' ')
            {
                flag2 = 2;
                break;
            }
        }
    }

    if (flag2 == 2)
    {
        printf("Yes");
    }
    else
        printf("No");
}
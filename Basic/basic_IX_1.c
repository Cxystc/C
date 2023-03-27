#include <stdio.h>
#include <string.h>
int calculation(char *s)
{
    int i = 0;
    int flag = 0;
    float A = 0; //第一个运算数
    float B = 0;
    char c; //运算符
    while (s[i] != '\0')
    {
        if (flag == 0)
        {
            if (s[i] >= '0' && s[i] <= '9') //首先它确实是个数字
            {
                A = A * 10 + (s[i] - '0');
            }
            else if (s[i] == ' ')
            {
                i++;
                continue;
            }
            else
            {
                printf("Input Error!");
                return 0;
            }
            if (s[i + 1] < '0' || s[i + 1] > '9')
            {
                flag = 1;
                i++;
            }
            else
            {
                i++;
                continue;
            }
        }

        if (flag == 1)
        {
            if (s[i] == '*' || s[i] == 'x' || s[i] == 'X')
            {
                c = '*';
            }
            else if (s[i] == '+')
            {
                c = '+';
            }
            else if (s[i] == '-')
            {
                c = '-';
            }
            else if (s[i] == '/')
            {
                c = '/';
                if (B == 0){
                    printf("Dividing by zero explained");
                    return 0 ; 
                }
            }
            else if (s[i] == ' '|| s[i] == '\0')
            {
                i++;
                continue;
            }
            else
            {
                printf("Input Error!");
                return 0;
            }
            i++;
            flag = 2;
        }

        if (flag == 2)
        {
            if (s[i] >= '0' && s[i] <= '9') //首先它确实是个数字
            {
                B = B * 10 + (s[i] - '0');
            }
            else if (s[i] == ' ')
            {
                i++;
                continue;
            }
            else
            {
                printf("Input Error!");
                return 0;
            }
            if (s[i + 1] < '0' || s[i + 1] > '9')
            {
                break;
            }
            i++;
        }
    }
    float result = 0;
    if (c == '*')
        result = A * B;
    if (c == '/')
        result = A / B;
    if (c == '+')
        result = A + B;
    if (c == '-')
        result = A - B;
    printf ("result = %f", result); 
    return 0 ;
}

int main()
{
    char list[29];
    // scanf("%s", list);//注意这里的问题 这是个万能函数，不过缺陷是，遇到空格就会截断
    gets (list) ; 
    calculation(list);
}
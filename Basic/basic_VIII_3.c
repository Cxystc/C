#include <stdio.h>
#include <string.h>

int main()
{
    //abcdefghABCDE56xy123xyxyABCDE
    char resource[50] = "abcdefgh123456xy123xyxy1234";
    printf("resouce: %s\n", resource);
    int len1 = 0;
    char target[] = "1234";
    int len2 = 0;
    char alternate[] = "ABCDE";
    int len3 = 0;
    while (1)
    {
        len1 += 1;
        if (resource[len1] == '\0')
            break;
    }
    while (1)
    {
        len2 += 1;
        if (target[len2] == '\0')
            break;
    }
    while (1)
    {
        len3 += 1;
        if (alternate[len3] == '\0')
            break;
    }

    for (int i = 0; i < len1; i++)
    {
    int flag = 114514;
        if (resource[i] == target[0])
        {
            for (int j = 1; j < len2; j++)
            {
                if (resource[i + j] != target[j])
                {
                    flag = 114514;
                    break;
                }
                flag = i;
            }
        }
        //得到下标i
        if (flag != 114514)
        {
            int delta = len3 - len2;
            if (delta >= 0)
            {
                for (int j = len1 - 1; j >= len2 + i; j--) //从后开始挪动，防止吃掉数据
                {
                    resource[j + delta] = resource[j];
                } //挪动
            }
            else if (delta < 0)
            {
                for (int j = len2 + i + 1; j < len1; j++)
                {
                    resource[j] = resource[j + delta];
                }
            }

            for (int z = 0; z < len3; z++)
            {
                resource[i + z] = alternate[z];
            }
        }
    }
    printf("result:%s\n",resource);
}
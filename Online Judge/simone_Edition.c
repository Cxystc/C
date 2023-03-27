#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char s[10000];
        char k[10];
        // printf("input s: ");
        scanf("%s", &s);
        getchar();
        // printf("input k: ");
        scanf("%s", &k);
        int j = 0;
        int LEN = 0;
        int flag = 0;
        while (s[j])
        {
            flag = 0; //最开始就是不行的
            if (s[j] == k[0])
            {
                flag = 1; //原来以为你很行
                for (int i = 0; i < strlen(k); i++)
                {
                    if (s[j + i] != k[i])
                    {
                        flag = 0; //就是说不行
                    }
                }
                if (flag == 1)
                {
                    LEN++;
                }
            }
            j++;
        }
        printf("%d\n", LEN);
    }
}
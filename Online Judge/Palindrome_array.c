#include <stdio.h>
#include <stdlib.h>
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int LEN;
        scanf("%d", &LEN);
        int a[LEN];
        for (int i = 0; i < LEN; i++)
        {
            scanf("%d", &a[i]);
        } //获取数组

        int X[LEN];
        for (int i = 0; i < LEN; i++)
        {
            X[i] = 0;
        }
        int index_x = 0;
        int dex = 0;
        for (int i = -1000; i <= 1000; i++)
        {
            for (int j = 0; j < LEN; j++)
            {
                if (a[j] == i)
                {
                    X[index_x]++;
                    dex = 1;
                }
            }
            if (dex == 1)
            {
                index_x++;
                dex = 0;
            }
            //在这里面的就是同一个数字
        }
        index_x = 0;
        int flag = 0;
        while (X[index_x++] != 0)
        {
            if (X[index_x] % 2 == 1)
                flag++;
        }
        if(LEN %2 == 0){
            if( flag >= 1 ) {
                printf("No\n");
                continue;
            }
        }
        if (LEN %2 == 1) {
            if (flag >= 2 ){
                printf("No\n");
                continue;
            }
        }
    printf("Yes\n");
    }
}
//超时了淦

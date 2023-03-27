#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int t, k;
    scanf("%lld %lld", &t, &k);
    int x[100001] = {0}; // 第i个人进入的时间
    int y[100001] = {0};

    int z[121] = {0};
    int q[121] = {0};
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }

    for (int i = 0; i < 121; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if ((x[j] <= i) && (y[j] >= i))
            {
                z[i]++;
            }
        }
    }

    int a, b; // 前后界限
    for (int i = 0; i < 121; i++)
    {
        if (z[i] < k)
            q[i] = 1;
    }
    // 得到一个q q[i] 是一就可以
    int N = 0 ; 
    for ( int i = 0 ; i < 121; i++){
        if (i == 0 ){
            if (q[i] == 1)N++;
        }
        else{
            if (q[i] == 0 && q[i+1] == 1)N++;
        }
    }
    printf("%d\n",N);
    for (int i = 0; i < 121; i++)
    {
        a = 0;
        b = 0;
        if (i == 0)
        {
            if (q[i] == 1)
            {
                a = i;
                for (int j = i + 1; j < 121; j++)
                {
                    if (q[j] == 0 && q[j - 1] == 1)
                    {
                        b = j-1;
                        i = j;
                        printf("%d-%d\n", a, b);
                        break;
                    }
                }
            }
        }

        if (q[i] == 1 && q[i-1] == 0 && q[i+1] == 0 ) {
            printf("%d-%d\n",i,i);
        }
        if (q[i] == 0 && q[i + 1] == 1) // 不是第一个
        {
            a = i + 1;
            for (int j = i + 1; j < 121; j++)
            {
                if (q[j] == 0 && q[j - 1] == 1)
                {
                    b = j-1;
                    i = j-1;
                    printf("%d-%d\n", a, b);
                    break;
                }
            }
        }
    }
}
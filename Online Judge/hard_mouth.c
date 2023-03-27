#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    long long pi[N], ai[N], bi[N];
    long long maxpi = 0;//这个是最远的距离
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld %lld", &pi[i], &ai[i], &bi[i]);
        if (pi[i] > maxpi)
            maxpi = pi[i];
    }
    int t;
    int BLOOD[maxpi + 1];
    for (t = 0; t < maxpi + 1; t++)
    {
        int blood = 0;
        for (int i = 0; i < N; i++)
        { //每一个位置得到一个血量
            if (t >= (pi[i] - ai[i]) && t <= (pi[i] + ai[i]))
            {
                blood -= bi[i];
            }
        }
        BLOOD[t] = blood;
    }
    int maxblood = 0;
    for (int i = 0; i < maxpi + 1; i++)
    {
        if (BLOOD[i] < BLOOD[maxblood])
            maxblood = i;
    }
    printf("%d", maxblood);
}
#include <stdio.h>
int main()
{
    int T, A, B, C;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        float Me = 0; //储存我和xxx的分数
        scanf("%d %d %d", &A, &B, &C);
        if(A < 0 || B < 0 || C < 0 || A + B + C == 0 )return 0 ; 
        //两个人同出红或者绿的概率分别是1/4；
        //两个人出不一样的概率是1/2；
        Me += (float)A * 0.25;
        Me += (float)B * 0.25;
        Me -= (float)C * 0.5;
        printf("%f \n", Me);
    }
}
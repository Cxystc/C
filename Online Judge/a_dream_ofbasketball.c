#include <stdio.h>
int main()
{
    long long d;
    scanf("%lld", &d);
    int a[d];
    for (int i = 0; i < d; i++)
    {
        scanf("%d", &a[i]);
    }
    //选择
    int SG[d+1];
    SG[d] = 0 ;  
    for (int i = 1 ; i <= d ; i ++){
        SG[i] += a[i] ;//选择第一个
        for ( int j = i ; j < d ; j++){
            
        }
    }
    printf("%d",SG);

}
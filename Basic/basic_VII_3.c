#include <stdio.h>
#include <math.h>


int main (){
    int n ; 
    long long sum = 0 ; 
    scanf("%d",&n);//获取长度
    for (int i = 1 ; i <= n;i++){//多少项
        long long s = 0 ; 
        for ( int j = 1 ; j <= i;j ++){
            s += i* 1 *pow(10, j-1); //n作为次数
        } 
        sum += s;
        }
    printf("%d\n",sum);
}
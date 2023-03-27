//实现1——20的连乘的相加
#include <stdio.h>
#include <string.h>
#include <math.h>

int main ()
{   
    long int sum = 0 ; 
    for (int j = 1; j <= 20 ;  j++)
    {
        long int p = 1 ; 

        for (int i = 1 ; i <= j; i ++)//实现阶乘
        {
             p *= i  ;
        }
        sum += p ; 
    }
    printf("sum = %d\n",sum);

}
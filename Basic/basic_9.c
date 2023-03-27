#include<stdio.h>
#include<math.h>

int A(double n)
{
    double a=pow(16,-n)*(4/(8*n+1)-2/(8*n+4)-1/(8*n+5)-1/(8*n+6));
    return a;
}

int main()
{
    double m;
    printf("input your number:");
    scanf("%lf",&m);//m是输入的
    double n=0;
    while(A(n)>m)
 {
    n = n + 1 ;
    printf("The %d time. \n",n);
 }
    printf("final_n:%f",n);
}
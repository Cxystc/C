//2. 使用函数递归方式编程,显示计算1+2+3…+30, 显示计算过程中各个累加值
#include <stdio.h> 
int adding (int sum , int n , int max ); 
int adding (int sum , int n ,int max ){
    sum += n ; 
    printf("%d ",sum);
    if (n == max) return sum ; 
    n++;
    adding (sum,n,max);
}

int main (){
    int sum = adding (0,1,30);
}

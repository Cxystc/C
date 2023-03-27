#include <stdio.h>
#include <math.h>


int main () {
    //定义一个反转函数,返回值是一个数
    int reversing (int n);
    //暴力枚举
    for ( int i = 1 ; i <=10 ; i++){
        for (int j  = 10000 ; j < 100000;j ++){
            int m = reversing (j);
            if (j * i == reversing(j))printf("%d %d\n",i,j);
        }
    }

}
int reversing (int n) {
    //n5位数
    int m = 0 ; 
    for ( int i = 1 ; i <= 5 ; i++){
        int a  = n%10 ; 
        m += a*pow(10,5-i);
        n /= 10 ;
    }
    return m ; 
}

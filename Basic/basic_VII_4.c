#include <stdio.h>
#include <string.h>

int main (){
    int n ;
    scanf("%d",&n);

    if( n % 2 == 0 ) n = n-1 ; //如果是偶数，强制转换为奇数

    //前面半段
    for (int i = 1 ; i <= (n+1)/2 ;i++ ){
        for (int j = 0 ; j < (n - (2*i -1) )/2;j++) {
            printf(" ");
        }
        for (int j = 0 ; j < 2*i -1  ; j ++){
            printf("*");
        }
        printf("\n");
    }

    //后半段
 
    for ( int i = ((n+1)/2 )+1 ; i <= n ; i++ ){
        for (int j = 0 ; j < i - (n+1)/2 ; j ++ ) {
            printf(" ");
        }
        for (int j = 0 ; j < n - 2*(i - (n+1)/2) ; j++){
            printf("*");   
        }
        printf("\n");
    }
}

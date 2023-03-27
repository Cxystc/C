#include <stdio.h>

int main (){
    int sum =0 ; 
    for (int i = 1 ; i <= 200 ;i++){//循环
        if (i % 3 == 0 && i % 5 != 0 )sum += i;//判断
    }
    //输出
    printf("%d\n",sum);
    
}
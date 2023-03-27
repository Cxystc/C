//汉诺塔问题 暂时还没有懂

#include <stdio.h>
#include <string.h>

int main () {
    void hanoi (int n , char target , char auxiliary , char resource);
    int n = 3 ; 
    hanoi (n ,'A','B','C');
}

void hanoi ( int n ,  char resource ,char target , char auxiliary ){   
    static int i = 1 ; //用static防止每次都被清零

    if (n == 1 ) {
        printf("No.%d Move %c to %c \n",i, resource, target);
        i++;
    }
    
    else {
        hanoi (n -1 ,resource,auxiliary,target);//将n-1个盘子从目标盘移动到辅助盘，此时target盘做辅助盘；
        printf("No.%d Move %c to %c \n",i,resource,target);//将剩下的一个盘子放到目标位置；
        i ++ ; 
        hanoi (n-1 , auxiliary,target,resource);//最后把aux盘上的n-1个盘子放到target盘子上，此时，resource做辅助盘
    }
}
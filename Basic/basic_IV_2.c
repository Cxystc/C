//画一个图案
#include <stdio.h>
#include <string.h>

int main ()
{
        for ( int j = 0,i = 10  ; j <= 10 ,i >= 0  ; i-- , j++ )//假设每一行有10个符号
         { 
            for (int k = 0 ; k <= i ; k++)printf(" ");
            for (int t = 0 ; t <= j ; t++)
            {  
                printf("*");
                if (t == j)printf("\n");
            }
         }


          for ( int j = 0,i = 10  ; j <= 10 ,i >= 0  ; i-- , j++ )//复制
         { 
            for (int t = 0 ; t <= j ; t++) printf(" ");
            for (int k = 0 ; k <= i ; k++)
            {
                printf("*");
                if (k == i ) printf("\n");
            }

         }

}
#include <stdio.h>
#include <string.h>
int main (){
    char a[10] = "123456789";
    int b[10] ; 
    for (int i = 0 ; i < 10 ;  i++){
        b[i] = a[i] - '0';
    }
    for (int i = 0 ; i < 9 ;  i++){
        printf("%d ",b[i]);
    }

}


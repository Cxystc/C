#include <stdio.h>
#include <math.h>

int main (){
    int n; 
    long long  j; 
    int g = 0 ; 
    while (1){
        n = pow (2,g);
        j = pow (2,g); 
        if (n != j ){
            printf("Error : %d\n",g);
            break;
        }
        g++; 
    }
}
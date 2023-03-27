//判断数组是否相等
#include <stdio.h>

int main(){
    int arr[20],a1,d,a1_,d_; 
    for ( int i = 0 ;  i < 100 ; i++){
        a1 = i ; 
        for ( int i =0 ;  i < 100 ; i ++){
            d = i ; 
            if (4*a1 + 6*d == 26){
                if (a1*(a1 + d )*(a1 + 2*d)*(a1 + 3*d) == 880){
                    printf("%d\n%d\n",a1,d);
                    a1_ = a1; 
                    d_ = d ; 
                    break;
                }
            }
        }
    }
    //得到等差数列的a1 = 2 和 d =3 ;  
    for ( int i = 0 ; i < 20 ; i++){
        arr[i] = a1_ + d_*(i);
    }

    for (int i = 1 ; i < 21 ; i++){
        printf("%d ",arr[i-1]);
        if (i%5 == 0 ){
            printf("\n");
        }
        
    }
    
}
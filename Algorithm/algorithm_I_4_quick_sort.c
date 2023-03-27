//快速排序；
#include <stdio.h>

int quick_sort(int * list , int left, int right) ; 
int recursing(int * list , int Left , int Right );
int reposition (int * list , int left , int right) ; 
int main () 
{
    int list [] = {9,8,75,6,3,5,23,4,5,4,63};
    int list2 [] ={9,8,75,6,3,5,23,4,5,4,63};
    quick_sort(list, 0,10);
    quick_sort(list2 ,5,10);
    return 0 ; 
}

int recursing(int * list , int Left , int Right) {
    if (Left < Right ){
        int mid = reposition(list , Left,Right);
        recursing(list ,Left, mid -1 ) ; 
        recursing(list, mid + 1 , Right);
    }
}

int reposition(int * list , int left , int right){
    int temp = list[left]; 
    while (left < right ) {
        while ( list[right] >= temp && right > left) {
            right -= 1 ;
        }
        list[left]=list[right]; 
        while ( list[left] <= temp && left < right){
            left += 1 ;
        }
        list[right] = list[left] ; 
    }
    list [left ] = temp ;
    return left ; 
}

int quick_sort(int * list , int left , int right){
    for  (int i = 0 ; i < right ; i++){
    printf("%d ",list[i]);  
}
    printf("\n");
    recursing(list,left , right);
    for  (int i = 0 ; i < right ; i++){
        printf("%d ",list[i]);
}
    printf("\n");      
}
//排序;
#include <stdio.h>
    int quick_sort(char *list , int left , int right) ;
    int recursing(char * list , int Left , int Right ) ; 
    int reposition (char *list , int left , int right ); 

int main (){
    char a [200] ; 
    scanf("%s",a);
    int i = 0 ; 
    while (1){
        if (a[i] == '\0'){
            break; 
        }
        i++; 
    }
    quick_sort(a ,0 , i-1) ; 
}

int quick_sort(char * list , int left , int right ){
    recursing(list , left , right);
    printf("%s ",list);

}

int recursing(char * list , int Left , int Right ) {
    if (Left < Right ){
        int mid = reposition(list , Left , Right ) ; 
        recursing(list , Left , mid -1  );
        recursing ( list , mid + 1 , Right ); 
    }
}

int reposition ( char * list , int left ,int  right ){
    char temp = list[left];
    while (left < right){
        while (list[right] >= temp  && right > left){
            right -=1 ;
        }   
        list[left] = list [right];
        while ( list [left ] <= temp && right > left ){
            left += 1 ; 
        }
        list[right] = list[left]; 
    }
    list [left] = temp  ;
    return left ; 
}
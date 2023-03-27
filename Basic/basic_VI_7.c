#include <stdio.h>

int main (){
    int first ; 
    printf("input:");
    scanf("%d",&first);
    char ch ; 
    int num ;
    while (1){
        printf("input:");
        getchar();//吃掉换行符
        fflush(stdin);
        scanf("%c",&ch);
        if (ch == ';')break;
        printf("input:");
        scanf("%d",&num);
        if (ch == '+'){
            first += num ;
        }
        else if (ch == '-'){
            first -= num ;
        }
    }
    printf("%d\n",first);
}

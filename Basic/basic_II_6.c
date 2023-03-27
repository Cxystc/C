#include <stdio.h>
#include <string.h>

int main ()
{   
    int a = 1, b = 2 ,c[2];
    void switch1(int a, int b );
    void switch2(int *a,int *b);
    int switch3(int a,int b,int *c);

    printf("Before : %d %d \n",a, b );
    switch1(a,b);
    printf("After 1 : %d %d ",a,b);//实际上没有换，这是为毛啊
    switch2(&a,&b);
    printf("After 2 : %d %d  ",a,b);
    switch3(a,b,c);
    printf("After 3 : %d %d",c[0],c[1]);
    
    return 0; 
}
void switch1(int a ,int b)//直接交换
{
    int t = a ;
    // printf("\nbefore a : %d \n",a );
    a = b ;
    // printf("after a : %d\n",a );
    // printf("before b : %d\n",b);
    b = t ;
    // printf("after b : %d\n",b);
    printf("after 1 inside %d %d \n",a,b);//在函数的内部是交换成功的

}

void switch2(int *a,int *b)//用指针交换
{
    int t = *a ;
    *a = *b ;
    *b = t;
}

int switch3(int a ,int b,int *c)
{
    c[0] = b;
    printf("c0 = %d \n ",c[0]);
    c[1] = a;
    printf("c1 = %d \n ",c[1]);
}
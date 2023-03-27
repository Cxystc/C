#include <stdio.h>
#include <string.h>
//普通的变量的指针
int main()
{
    int a = 1 ;
    printf("&a = %d\n",&a);//a的地址
    printf("a = %d\n",a);
    int *p = &a ;
    printf("p = %d\n",p);//p的内容，就是一个a的地址
    printf("*p = %d\n",*p);//p指向的地址的内容，就是a的内容
    //得到结果a = *p ; &a = p ;
    //数组指针,首先是一个数组：*p，然后指向了一个数组
    int arr[4] = {1,2,3,4};
    // (*pp)[10] = arr[10];输出一个非法的地址

    //数组指针
    int *pp = &arr[0];//int *pp = arr;结果是一样的
    printf("*pp[2] = %d\n", *pp+1);//这个应该是2
    printf("&arr = %d \n",&arr);
    printf("pp = %d \n",pp);//pp的内容，应该是&arr
    printf("*pp = %d \n",*pp);//pp指向的地址的内容，应该是一个数组的首个元素1
    return 0;
}

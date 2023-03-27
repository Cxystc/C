#include <string.h>
#include <stdio.h>
#include <stdlib.h> //用于动态分配内存
struct Teacher
{
    int age;
    float height;
    char name[20];
    char address[];//flexible array must at the end of the strcut就是没有规定大小的数组要放最后
}Limingyi , leanna; 

int main()
{
    Limingyi.age = 28;
    // Limingyi.name = "Mingyi Li";//在定义之外不能这样赋值
    // Limingyi.address = "Shunde daliang";
    strcpy (Limingyi.name, "LImingyi ");
    strcpy (Limingyi.address, "Shunde daliang");
    Limingyi.height = 158; 
    printf("%d\n%s\n%s\n%.4f\n",Limingyi.age,Limingyi.name,Limingyi.address,Limingyi.height);
    scanf("%d%s%s%f",&leanna.age,leanna.name,leanna.address,&leanna.height);
    printf("%d\n%s\n%s\n%.4f\n",leanna.age,leanna.name,leanna.address,leanna.height);
    return 0;
}
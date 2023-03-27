#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//用动态内存分配来给5个学生判断有没有挂科的现象，有的话就输出这个同学的信息
//versin2：用结构体来编辑学生的姓名，班级，学号，成绩，然后输出不及格的学生的班级学号和姓名
struct Students
{
    int class;
    long int number; 
    char name[20];
    int score; 
    //可以升级为链表
} ;//要用结构体数组才能实现循环
//这种表达方法比较高效

int main()
{   //函数声明
    struct Students input(struct Students *);//初始化每个学生的结构体
    int  comparing(struct Students *);//比较各个学生的成绩，返回的是这个学生的下标
    void output(struct Students *, int );//输出最终学生的信息

    struct Students List[3] ;
    int  stu; //变量声明:这个是学生下标

    input(List);//List 是结构体数组
    // stu  = comparing(List);
    // output*(stu);//这是一个学生的下标
    
    stu = comparing(List);
    output(List,stu);
}   

struct Students input (struct Students *list )
{
    for (int i = 0 ; i < 3 ; i++){
        printf("Please input NO.%d student`s information :\n",i+1);
        scanf("%d %ld %s %d",&list[i].class,&list[i].number,&list[i].name,&list[i].score);
        if (i == 3 )printf("Finished\n");
    }
}

int comparing(struct Students *list)
{
    int max = 0 ;
    for (int i = 0;i < 3 ; i++ ){
        if (list[i].score > list[max].score) max = i ;
    }
}

void output (struct Students *list,int j)
{
    printf("The best student is :%s from %d calss,number : %ld\n",list[j].name,list[j].class, list[j].number);
    printf("Her or His score is :%d\n",list[j].score);
}
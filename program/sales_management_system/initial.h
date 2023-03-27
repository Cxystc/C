#ifndef _INITIAL_H_//如果没有定义
#define _INITIAL_H_//则执行下面的代码

typedef struct W {
    long long int Number ;
    long long int Product1 ; 
    long long int Product2 ; 
    long long int Product3 ; 
    long long int Product4 ; 
    long long int Product5 ; 
    int Amount1 ; 
    int Amount2 ;
    int Amount3 ;
    int Amount4 ;
    int Amount5 ;
    struct W *Next ;
} Workers ;//链表，储存4个销售员；

//下面是储存查询对应商品的销售额的结构体；
typedef struct A{
    long long ProductNumber ; 
    int Amounta;
    int Amountb;
    int Amountc;
    int Amountd;//一共是四个员工
}Product_Statistics;

//下面是储存查询对应员工的销售额的结构体
typedef struct B{
    long long WorkerNumber; 
    int Amount1;
    int Amount2;
    int Amount3;
    int Amount4;
    int Amount5;//一共是五种产品
}Worker_Statistics;
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date
{
    int year ; 
    int month;
    int day ; 
};
struct studentNode {
    char name [10];
    struct date birth ;
    struct studentNode *next;
};

char *oldest (struct studentNode *L)
{
    struct studentNode * p;
    struct studentNode * p2 ; 
    p = L;
    p2 = L;
    //把首个指针传进来；p2是辅助指针

    while (1)
    {   
        if (p->birth.year < p2->birth.year)p2 = p;
        if (p->birth.year ==  p2->birth.year){
            if (p->birth.month  < p2->birth.month )
            {p2 = p ; }
            if (p->birth.month  == p2->birth.month){
                if (p->birth.day <= p2->birth.day)
                {p2 = p;}
            }
        }
        p = p->next;
        if (p == NULL)break; 
    }
return p2->name;
}
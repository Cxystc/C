#include <stdio.h>
#include <stdlib.h>

struct date
{
    int year;
    int month;
    int day;
};

struct student
{
    char name[20];
    struct date birth;
};

char *oldest(struct student s[], int n) //有n个要比较的对象
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].birth.year > s[m].birth.year)m = i;
        else if (s[i].birth.year =  s[m].birth.year){
            if (s[i].birth.month  > s[m].birth.month )m = i ; 
            else if (s[i].birth.month  = s[m].birth.month){
                if (s[i].birth.day >= s[m].birth.day)m = i ;
            }
        }
    }
    return s[m].name;
}
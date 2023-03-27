// memset初始化结构体 void *memset(void *str, int c, size_t n)

#include <stdio.h>
#include <string.h>

struct test
{
    int a;
    int b;
    int c[10];
};
int main()
{
    struct test Testing;
    memset(&Testing, 0, sizeof(struct test));
    printf("%d %d", Testing.a, Testing.b);

    printf("\n");

    int list[10];

    for (int i = 0 ; i < 5 ; i++){
        memset(&list[i],1,sizeof(int)*4);
    }
    for ( int i = 0 ; i < 10 ; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    char str[50];
    strcpy(str,"This is string.h library function");
    memset(str,'&',10);
    printf("%s",str);//&&&&&&&&&&ring.h library function
}
//实现动态链表函数，删除增加清空和遍历；
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Struction
{
    int data;
    struct Struction *next;
};

void main()
{
    struct Struction *Creating();                             //创建一个动态链表
    struct Struction *RunThrough(struct Struction *);         //遍历链表
    struct Struction *Adding(struct Struction *, int data);   //向链表中添加结点
    struct Struction *Removing(struct Struction *, int data); //删除列表的某个结点
    struct Struction *Clear(struct Struction *);              //清空列表
    struct Struction *Free(struct Struction *);               //销毁列表

    struct Struction *flexible_struction = Creating();
    int a = 5;
    flexible_struction = Adding(flexible_struction, a);
    flexible_struction = Removing(flexible_struction, a);
    Clear(flexible_struction);
    flexible_struction = Free(flexible_struction);//空间被释放了，所以现在的flexible是野指针；
    RunThrough(flexible_struction);
    
}

struct Struction *Creating()
{
    struct Struction *head;    //头指针
    struct Struction *p1, *p2; //辅助指针

    head = malloc(sizeof(struct Struction));
    printf("Please input your data:\n");
    scanf("%d", &head->data);
    p1 = head; //初始化链表

    while (1)
    {
        p2 = malloc(sizeof(struct Struction)); //开辟空间//p2重新赋值
        printf("Please input your data ,use '-1'to break the loop:\n");
        // scanf("%d", &p2->data);

        int dt;
        scanf("%d", &dt);
        p2->data = dt;

        if (p2->data == -1)
        {
            p1->next = p2; // 最后一个结点也要连起来，不然就会出现野指针
            p2->next = NULL;
            break; //判断退出
        }

        p1->next = p2; // 连接前面和后面
        p1 = p2;       // p1指针移动
    }
    return head;
}

struct Struction *RunThrough(struct Struction *a) //遍历链表；最后一个data是不会被打印的
{
    struct Struction *p1;
    p1 = a;
    while (1) //不能读空指针//Segmentation fault
    {
        if (p1->next == NULL) // Segmentation fault
            break;
        else
        {
            printf("%d\n", p1->data);
            p1 = p1->next;
        }
    }
}

struct Struction *Adding(struct Struction *a, int data)
{ //一定要放在-1前面，因为最后一个data是不打出来的
    struct Struction *p1 = a;
    while (1)
    {
        p1 = p1->next; //找到NULL
        if (p1->next == NULL)
        {
            p1->data = data;
            break;
        }
    }
    struct Struction *p2 = malloc(sizeof(struct Struction));
    p2->data = -1;
    p2->next = NULL;
    p1->next = p2;
    return a;
}

struct Struction *Removing(struct Struction *a, int data)
{
    struct Struction *p1 = a->next;
    struct Struction *p2 = a;
    if ( p2->data == data ) {
        p2 = p1  ; 
        return p2;
    }
    else
    {
        while (1)
        {
            if (p1->data == data){
                p2->next = p1->next; 
                return a;
            }
            p2 = p1 ;       //p2 followed p1 
            p1 = p1->next;
        }
        
    }
}

struct Struction *Clear(struct Struction *a) {
    struct Struction *p1 ,*p2 ; 
    if (a->next == NULL)return a ; 
    p2 = a->next ; 
    p1 = a ; 
    while (1) {
        p1->data = 0;
        p1 = p2 ;
        p2 = p2->next ;
        if ( p2 -> next == NULL){
            p1 ->data = 0;
            p2->data = 0; 
            return a; 
        }
    }
}

struct Struction *Free(struct Struction *a) {
    printf("Are you sure you want to free this struction?\n");
    char b;
    scanf("%s",&b);
    if (b == 'y');
    else return a ;
    struct Struction *p1 ,*p2;
    p1 = a ;
    p2 = a->next ;
    if (a->next == NULL ) free(a);
    else{
        free(p1);
        p1 = p2 ; 
        p2 = p2->next ; 
        if ( p2->next == NULL) {
            free(p1);
            free(p2);
            a->next = NULL;
            a->data = 0 ;
            return a ; 
        }
    }
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

typedef struct NODE_
{
    char data[100];
    struct NODE_ *next;
} NODE;

NODE *creating(void)
{
    //初始化头结点
    NODE *Node;
    Node = (NODE *)malloc(sizeof(NODE));
    NODE *p1 = Node; //前结点
    Node->next = NULL;
    memset(&Node->data, 0, sizeof(NODE));
    printf("Please input data : (type enter to break ) : \n");
    scanf("%[^\n]", &p1->data);
    NODE *p2; //后结点
    if (*p1->data == '\r')
    {
        p1->next = NULL;
        return NULL;
    }
    else
    {
        while (1)
        {
            p2 = (NODE *)malloc(sizeof(NODE));
            memset(&p2->data, 0, sizeof(NODE));
            fflush(stdin);
            char *a;
            a = (char *)malloc(sizeof(char) * 100);
            scanf("%[^\n]", a);
            if (*a == '\r')
                return Node;
            strcpy(p2->data, a);
            p1->next = p2;
            p1 = p2;
            p2->next = NULL;
            free(a);
        }
    }
}

void traverse(NODE *p)
{
    while (1)
    {
        printf("%s\n", p->data);
        if (p->next == NULL)
            break;
        p = p->next;
    }
}

void search(NODE *p)
{
    char a[100] = {'\0'};
    printf("Please input the target string: \n");
    scanf("%s", a);
    if (p == NULL)
    {
        printf("make sure there something in the linklist!\n");
    }
    while (1)
    {
        if (strcmp(p->data, a) == 0)
        {
            printf("Found it!\n");
            return;
        }
        else
        {
            if (p->next == NULL)
            {
                printf("coundn`t found it!\n");
                return;
            }
            p = p->next;
        }
    }
}

void writefile(NODE *resource)
{
    FILE *file = fopen("D:/My_code/Cxystc-Python_selfteaching-1/C/Experiment/data.txt", "w");
    while (1)
    {
        fputs(resource->data, file);
        fputs("\n", file);
        if (resource->next == NULL)
        {
            printf("Finished\n");
            break;
        }
        resource = resource->next;
    }
    fclose(file);
}

void readfile(NODE *target)
{
    //找到末尾结点；
    while (1)
    {
        if (target->next == NULL)
        {
            break;
        }
        target = target->next;
    } // target是原来的最后一个结点
    NODE *p1;
    p1 = target;
    NODE *p2;
    FILE *file = fopen("D:/My_code/Cxystc-Python_selfteaching-1/C/Experiment/resource.txt", "r");
    while (1)
    {
        char buff[100] = {'\0'};
        fgets(buff, 100, file); //每次一行,(包括了换行)
        for (int i = 0; i < 100; i++)
        {
            if (buff[i] == '\n' || buff[i] == '\r')
            {
                buff[i] = '\0';
            }
        }
        //删掉换行符

        if (buff[0] == '\0')
        {
            printf("Reading finished \n");
            break;
        }

        p2 = (NODE *)malloc(sizeof(NODE));
        memset(p2, 0, sizeof(NODE));
        strcpy(p2->data, buff);
        p1->next = p2; //链接
        p1 = p2;
    }
    fclose(file);
}

int status = 0 ; 
void menu(int n, int flag, NODE *link1)
{ // int n 是高亮的位置
    switch (n)
    {
    case 0:
        printf("\n=============MENU=============\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("Creating a linklist");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\ntraverse the linklist");
        printf("\nsearch from the linklist");
        printf("\nwritefile to the linklist");
        printf("\nreadfile from the linklist");
        printf("\nExit");
        printf("\n==============================\n");
        break;
    case 1:
        printf("\n=============MENU=============");
        printf("\nCreating a linklist\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("traverse the linklist");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\nsearch from the linklist");
        printf("\nwritefile to the linklist");
        printf("\nreadfile from the linklist");
        printf("\nExit");
        printf("\n==============================\n");
        if (flag == 1)
        {
            traverse(link1);
        }
        break;
    case 2:
        printf("\n=============MENU=============");
        printf("\nCreating a linklist");
        printf("\ntraverse the linklist\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("search from the linklist");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\nwritefile to the linklist");
        printf("\nreadfile from the linklist");
        printf("\nExit");
        printf("\n==============================\n");
        if (flag == 1)
        {
            search(link1);
        }
        break;
    case 3:
        printf("\n=============MENU=============");
        printf("\nCreating a linklist");
        printf("\ntraverse the linklist");
        printf("\nsearch from the linklist\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("writefile to the linklist");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\nreadfile from the linklist");
        printf("\nExit");
        printf("\n==============================\n");
        if (flag == 1)
        {
            writefile(link1);
        }
        break;
    case 4:
        printf("\n=============MENU=============");
        printf("\nCreating a linklist");
        printf("\ntraverse the linklist");
        printf("\nsearch from the linklist");
        printf("\nwritefile to the linklist\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("readfile from the linklist");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\nExit");
        printf("\n==============================\n");
        if (flag == 1)
        {
            readfile(link1);
        }
        break;
    case 5:
        printf("\n=============MENU=============");
        printf("\nCreating a linklist");
        printf("\ntraverse the linklist");
        printf("\nsearch from the linklist");
        printf("\nwritefile to the linklist\n");
        printf("readfile from the linklist\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("Exit");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\n==============================\n");
        if (flag == 1)
        {
            status = 1 ; 
        }
        break;
    }
}

void main()
{
    int n = 0;
    NODE *link1 = creating();
    menu(n, 0, link1);
    while (1)
    {
        if (kbhit())
        {
            char c = getch(); //读取按键，没有回车
            if (GetAsyncKeyState(VK_UP))
            {
                n--;
                menu(n, 0, link1);
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                n++;
                menu(n, 0, link1);
            }
            if (GetAsyncKeyState(VK_RETURN) & 0x8000)
            {
                menu(n, 1, link1);
                if (status == 1 )break;
                else menu(n,0,link1);
            }
            Sleep(100);
        }
    }
}

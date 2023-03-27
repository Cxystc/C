#include "initial.h"
#include "allinclude.h"
#include "function.h"
#include "setting.h"
int status = 0;
void menu(int, int, long long *, long long *, Workers *,int *);
void main()
{
    long long *ProductNumber = setting();                      //读取产品的编号和
    int *Price = Pricesetting();                               //价钱
    long long *WorkersNumber = wsetting();                     //读取员工编号
    Workers *head = creating(4, ProductNumber, WorkersNumber); //不保留输入人数接口
    int n = 0;
    menu(n, 0, ProductNumber, WorkersNumber, head,Price);
    while (1)
    {
        if (kbhit())
        {
            char c = getch(); //读取按键，没有回车
            if (GetAsyncKeyState(VK_UP))
            {
                n--;
                if (n < 0)
                    n = 6;
                system("cls");
                menu(n, 0, ProductNumber, WorkersNumber, head,Price);
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                n++;
                if (n > 6)
                    n = 0;
                system("cls");
                menu(n, 0, ProductNumber, WorkersNumber, head,Price);
            }
            if (GetAsyncKeyState(VK_RETURN) & 0x8000)
            {
                system("cls");
                menu(n, 1, ProductNumber, WorkersNumber, head,Price);
                if (status == 1)
                    break;
                else
                {
                    system("cls");
                    menu(n, 0, ProductNumber, WorkersNumber, head,Price);
                }
            }
            Sleep(100);
        }
    }
}

void menu(int n, int flag, long long *ProductNumber, long long *WorkersNumber, Workers *head,int *Price)
{ //高亮位置
    switch (n)
    {
    case 0:
        printf("\n=============菜单=============\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("            写纸条            ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\n          按员工统计          ");
        printf("\n          按产品统计          ");
        printf("\n         修改保存天数");
        printf("\n         修改员工工号         ");
        printf("\n         修改产品编号         ");
        printf("\n           退出系统");
        printf("\n==============================\n");
        if (flag == 1)
        {
            head = input(head, ProductNumber);
            if (head == NULL)
                return;
            time_t timep;
            time(&timep); //秒数
            char *date = getdate(timep);
            char *filename = getfilepath(date); //保留修改日期的接口
            infile(head, filename);             //保存 *
        }
        break;

    case 1:
        printf("\n=============菜单=============");
        printf("\n            写纸条            \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("          按员工统计          ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\n          按产品统计         ");
        printf("\n         修改保存天数");
        printf("\n         修改员工工号         ");
        printf("\n         修改产品编号         ");
        printf("\n           退出系统");
        printf("\n==============================\n");
        if (flag == 1)
        {
            long long wNumber;
            printf("请输入要查询的员工工号：\n");
            scanf("%lld", &wNumber);

            //查询是否有这个人：
            int flag = 0;
            for (int i = 0; i < 4; i++)
            {
                if (wNumber == WorkersNumber[i])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("未找到此工号！\n");
                system("pause");
                break;
            }

            Worker_Statistics *WS;
            WS = (Worker_Statistics *)malloc(sizeof(Worker_Statistics));
            int period;
            printf("请输入要查询的天数\n");
            scanf("%d", &period);
            WS = Wstatistic(wNumber, period); //按员工统计*
            //打印的函数
            Wprint(WS, ProductNumber,Price);
        }
        break;
    case 2:
        printf("\n=============菜单=============");
        printf("\n            写纸条            ");
        printf("\n          按员工统计         \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("          按产品统计          ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\n         修改保存天数");
        printf("\n         修改员工工号         ");
        printf("\n         修改产品编号         ");
        printf("\n           退出系统");
        printf("\n==============================\n");
        if (flag == 1)
        {
            long long pNumber;
            printf("请输入要查询的产品编号：\n");
            scanf("%lld", &pNumber);
            //查询是否有这个产品
            int flag = 0;
            for (int i = 0; i < 5; i++)
            {
                if (pNumber == ProductNumber[i])
                {
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                printf("未找到此产品！\n");
                system("pause");
                break;
            }
            Product_Statistics *PS;
            PS = (Product_Statistics *)malloc(sizeof(Product_Statistics));
            int period;
            printf("请输入要查询的天数\n");
            scanf("%d", &period);
            PS = Pstatistic(pNumber, period, ProductNumber); // 按产品统计 *
            //打印的参数
            Pprint(PS, WorkersNumber);
        }
        break;
    case 3:
        printf("\n=============菜单=============");
        printf("\n            写纸条            ");
        printf("\n          按员工统计         ");
        printf("\n          按产品统计          \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("         修改保存天数         ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\n         修改员工工号         ");
        printf("\n         修改产品编号         ");
        printf("\n           退出系统");
        printf("\n==============================\n");
        if (flag == 1)
        {
            kept_day(daysetting(1));
            printf("修改成功！\n");
            system("pause");
        }
        break;
    case 4:
        printf("\n=============菜单=============");
        printf("\n            写纸条            ");
        printf("\n          按员工统计         ");
        printf("\n          按产品统计          \n");
        printf("         修改保存天数\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("         修改员工工号         ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\n         修改产品编号         \n");
        printf("           退出系统           ");
        printf("\n==============================\n");
        if (flag == 1)
        {
            WorkersNumber = rwsetting();
        }
        break;
    case 5:
        printf("\n=============菜单=============");
        printf("\n            写纸条            ");
        printf("\n          按员工统计         ");
        printf("\n          按产品统计          \n");
        printf("         修改保存天数\n");
        printf("         修改员工工号         \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("         修改产品编号         ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\n           退出系统           ");
        printf("\n==============================\n");
        if (flag == 1)
        {
            ProductNumber = resetting();
        }
        break;
    case 6:
        printf("\n=============菜单=============");
        printf("\n            写纸条            ");
        printf("\n          按员工统计         ");
        printf("\n          按产品统计          \n");
        printf("         修改保存天数\n");
        printf("         修改员工工号         ");
        printf("\n         修改产品编号         \n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); //高亮
        printf("           退出系统           ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); //正常
        printf("\n==============================\n");
        if (flag == 1)
        {
            status = 1;
            kept_day(daysetting(0)); //默认清理缓存
        }
        break;
    }
}

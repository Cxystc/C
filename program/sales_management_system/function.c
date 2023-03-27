#include "allinclude.h"
#include "function.h"
#include "initial.h"
#include "setting.h"

Workers *creating(int Workers_amount, long long *ProductNumber, long long *WorkersNumber) //这里再传一个数组，可以自定义员工的工号
{
    Workers *p;
    Workers *pn;
    p = (Workers *)malloc(sizeof(Workers));
    Workers *head = p;
    for (int i = 0; i < Workers_amount; i++)
    {
        memset(p, 0, sizeof(Workers));
        p->Product1 = ProductNumber[0];
        p->Product2 = ProductNumber[1];
        p->Product3 = ProductNumber[2];
        p->Product4 = ProductNumber[3];
        p->Product5 = ProductNumber[4];
        if (i == 0)
        {
            p->Number = WorkersNumber[0];
        }
        if (i == 1)
        {
            p->Number = WorkersNumber[1];
        }
        if (i == 2)
        {
            p->Number = WorkersNumber[2];
        }
        if (i == 3)
        {
            p->Number = WorkersNumber[3];
        }
        if (i == 4)
        {
            p->Next = NULL;
        }
        if (i != 4)
        {
            pn = p;
            p = p->Next;
            p = (Workers *)malloc(sizeof(Workers));
            pn->Next = p; //链接并开辟
        }
    }
    return head;
}

Workers *input(Workers *head, long long *ProductNumber) 
{
    long long workers;
    printf("请输入员工的工号: \n");
    scanf("%lld", &workers);
    Workers *p = head;
    int flag = 0;
    for (int i = 0; i < 4; p = p->Next)
    {
        i++;
        if (p->Number == workers)
        { // 达到了链表的位置
            flag = 1;
            printf("输入对应商品的销售数目: \n");
            int P_num;
            for (int j = 0; j < 5; j++)
            {
                P_num = ProductNumber[j];
                switch (j)
                {
                case 0:
                    printf("%lld:", P_num);
                    scanf("%d", &p->Amount1);
                    break;
                case 1:
                    printf("%lld:", P_num);
                    scanf("%d", &p->Amount2);
                    break;
                case 2:
                    printf("%lld:", P_num);
                    scanf("%d", &p->Amount3);
                    break;
                case 3:
                    printf("%lld:", P_num);
                    scanf("%d", &p->Amount4);
                    break;
                case 4:
                    printf("%lld:", P_num);
                    scanf("%d", &p->Amount5);
                    break;
                }
            }
            system("pause");
            return head;
        }
    }
    if (flag == 0)
    {
        printf("您输入的工号有误\n");
        system("pause");
        return NULL;
    }
}

void infile(Workers *head, char *filename) //一口气直接，全部pull进去
{
    Workers *p;
    p = head;
    FILE *file = fopen(filename, "w+");
    for (int j = 0; j < 4; j++)
    {
        fprintf(file, "%lld\n", p->Number); //先打印员工的number
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
                fprintf(file, "%lld\n", p->Amount1); //按顺序输入产品的销售额
                break;
            case 1:
                fprintf(file, "%lld\n", p->Amount2);
                break;
            case 2:
                fprintf(file, "%lld\n", p->Amount3);
                break;
            case 3:
                fprintf(file, "%lld\n", p->Amount4);
                break;
            case 4:
                fprintf(file, "%lld\n", p->Amount5);
                break;
            }
        }
        p = p->Next;
    }
    fclose(file);
    printf("已保存\n");
}

char *getfilepath(char *filename)
{ //修改数据存储地址也在这里,这个函数最后得到一个文件的绝对路径
    FILE *file = fopen("./setting.txt", "a+");
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * 500);
    memset(buffer, 0, 500);
    fgets(buffer, 128, file);
    if (buffer[0] == '\0')
    {
        char path[128] = {0};
        printf("请输入数据保存地址\n");
        scanf("%s", path);
        fwrite(path, sizeof(char), strlen(path), file);
        fclose(file);
        return getfilepath(filename);
    }
    else
    {
        buffer = strcat(buffer, "/");
        buffer = strcat(buffer, filename);
        buffer = strcat(buffer, ".txt");
        fclose(file);
        return buffer;
    }
}

char *getdate(time_t timep) //把秒数变成日期的函数
{
    struct tm *p;
    p = gmtime(&timep);
    int ctime = p->tm_mday + (1 + p->tm_mon) * 100;
    char *date;
    date = (char *)malloc(sizeof(long) * 10);
    itoa(ctime, date, 10);
    return date;
}

void kept_day(int kept_day)
{
    // kept_day 保存的天数
    char *_date;
    _date = (char *)malloc(sizeof(char) * 10);
    time_t timep;
    time(&timep);
    timep -= (kept_day)*86400; //此时的日期就是开始删掉的日期
    _date = getdate(timep);

    //获取存放文件的路径
    while (1)
    {
        char *filepath;
        filepath = (char *)malloc(sizeof(char) * 100);
        filepath = getfilepath(_date);
        FILE *fp = fopen(filepath, "r");
        if (fp != NULL)
        {
            fclose(fp);
            remove(filepath);
            timep -= 86400;
            _date = getdate(timep);
        }
        else
        {
            break;
        }
    }
}

Product_Statistics *Pstatistic(long long Product_Number, int Period, long long *ProductNumber)
{
    int flag = 0;
    char *Number;
    Number = (char *)malloc(sizeof(char) * 128);

    lltoa(Product_Number, Number, 10);
    strcat(Number, "\n");
    Product_Statistics *Pstruct;
    Pstruct = (Product_Statistics *)malloc(sizeof(Product_Statistics));
    memset(Pstruct, 0, sizeof(Product_Statistics));
    Pstruct->ProductNumber = Product_Number;
    time_t timep;
    time(&timep); //今天的秒数
    for (int i = 0; i < Period; i++)
    {                       //在这个循环里就是同一个时期
        timep -= i * 86400; //得到对应天数
        char *date;
        date = (char *)malloc(sizeof(char) * 10);
        date = getdate(timep);
        char *filepath;
        filepath = (char *)malloc(sizeof(char) * 100);
        filepath = getfilepath(date);
        FILE *file = fopen(filepath, "r");
        Pstruct->ProductNumber = Product_Number;

        if (file != NULL)
        {
            for (int j = 1; j <= 5; j++)
            { //在这个循环里就是同一个文件
                char *buffer;
                buffer = (char *)malloc(sizeof(char) * 128);
                fgets(buffer, 128, file);
                memset(buffer, 0, 128);

                for (int z = 0; z < 5; z++)
                { //在这个循环里就是同一个小组5行

                    memset(buffer, 0, 128);
                    fgets(buffer, 128, file);
                    if (Product_Number == ProductNumber[z])
                    {
                        if (j == 1)
                        {
                            Pstruct->Amounta += atoi(buffer);
                            break;
                        }
                        if (j == 2)
                        {
                            Pstruct->Amountb += atoi(buffer);
                            break;
                        }
                        if (j == 3)
                        {
                            Pstruct->Amountc += atoi(buffer);
                            break;
                        }
                        if (j == 4)
                        {
                            Pstruct->Amountd += atoi(buffer);
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            continue;
        }
    }
    return Pstruct;
}

Worker_Statistics *Wstatistic(long long Worker_Number, int Period)
{
    char *Number;
    Number = (char *)malloc(sizeof(char) * 128);
    lltoa(Worker_Number, Number, 10);
    strcat(Number, "\n");
    Worker_Statistics *wstruct;
    wstruct = (Worker_Statistics *)malloc(sizeof(Worker_Statistics));
    memset(wstruct, 0, sizeof(Worker_Statistics));
    wstruct->WorkerNumber = Worker_Number;
    time_t timep;
    time(&timep); //今天的秒数
    for (int i = 0; i < Period; i++)
    {                       //同一个时期
        int flag = 0;       //标记
        timep -= i * 86400; //得到对应天数
        char *date;
        date = (char *)malloc(sizeof(char) * 10);
        date = getdate(timep);
        char *filepath;
        filepath = (char *)malloc(sizeof(char) * 100);
        filepath = getfilepath(date);
        FILE *file = fopen(filepath, "r");
        if (file != NULL)
        {
            do
            {
                char *line;
                line = (char *)malloc(sizeof(char) * 100);
                memset(line, 0, 100);
                fgets(line, 128, file);
                if (line[0] == '\0')
                    break;
                if (strcmp(line, Number) == 0)
                {
                    char *amount;
                    amount = (char *)malloc(sizeof(char) * 10);
                    memset(amount, 0, sizeof(char) * 10);
                    int a;

                    fgets(amount, 10, file);
                    a = atoi(amount);
                    wstruct->Amount1 += a;

                    memset(amount, 0, sizeof(char) * 10);
                    fgets(amount, 10, file);
                    a = atoi(amount);
                    wstruct->Amount2 += a;

                    memset(amount, 0, sizeof(char) * 10);
                    fgets(amount, 10, file);
                    a = atoi(amount);
                    wstruct->Amount3 += a;

                    memset(amount, 0, sizeof(char) * 10);
                    fgets(amount, 10, file);
                    a = atoi(amount);
                    wstruct->Amount4 += a;

                    memset(amount, 0, sizeof(char) * 10);
                    fgets(amount, 10, file);
                    a = atoi(amount);
                    wstruct->Amount5 += a;
                }
            } while (1);
        }
    }
    return wstruct;
}

void Pprint(Product_Statistics *P, long long *Wlist)
{
    printf("产品编号：%lld\n", P->ProductNumber);
    int index[4] = {0, 1, 2, 3};
    int target[4] = {
        P->Amounta,
        P->Amountb,
        P->Amountc,
        P->Amountd};
    int sum = 0;
    //排序:冒泡排序得了
    for (int i = 0; i < 4; i++)
    {
        sum += target[i];
        for (int j = 0; j < 4 - i - 1; j++)
        {
            if (target[j] < target[j + 1])
            {
                int temp = target[j];
                target[j] = target[j + 1];
                target[j + 1] = temp;

                int temp_index = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp_index;
            }
        }
    }

    for (int i = 0; i < 4; i++) //打印
    {
        printf("员工%lld:", Wlist[index[i]]);
        printf("%d\n", target[i]);
    }
    printf("总计：%d\n", sum);

    char filename[50]; //保存
    strcpy(filename, "Pstastic");

    char *change;
    change = (char *)malloc(sizeof(char)*50);
    lltoa(P->ProductNumber,change,10);
    strcat(filename,change);
    strcat(filename,"_");

    time_t timep;
    time(&timep);
    char *date = getdate(timep);
    strcat(filename, date);
    char *filepath = getfilepath(filename);
    FILE *file = fopen(filepath, "w+");
    for (int i = 0; i < 4; i++)
    {
        fprintf(file, "Worker%lld: ", Wlist[index[i]]);
        fprintf(file, "%d Pieces", target[i]);
        fprintf(file, "\n");
    }
    fclose(file);
    system("pause");
}

void Wprint(Worker_Statistics *W, long long *Plist, int *Price)
{
    printf("员工工号：%lld\n", W->WorkerNumber);
    int index[5] = {0, 1, 2, 3, 4};
    int target[5] = {
        W->Amount1,
        W->Amount2,
        W->Amount3,
        W->Amount4,
        W->Amount5};
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += target[i] * Price[i];
        for (int j = 0; j < 5 - 1 - i; j++)
        {
            if (target[j] < target[j + 1])
            {
                int temp = target[j];
                target[j] = target[j + 1];
                target[j + 1] = temp;

                int temp_index = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp_index;
            }
        }
    }

    for (int i = 0; i < 5; i++) //打印
    {
        printf("产品%lld:", Plist[index[i]]);
        printf("%d", target[i] * Price[index[i]]);
        printf("￥\n");
    }
    printf("总计：%d", sum);
    printf("￥\n");

    char filename[50]; //保存
    strcpy(filename, "Wstastic");

    char *change;
    change = (char*)malloc(sizeof(char) * 50);
    lltoa(W->WorkerNumber,change,10);
    strcat(filename,change);
    strcat(filename,"_");
    time_t timep;
    time(&timep);
    char *date = getdate(timep);
    strcat(filename, date);
    char *filepath = getfilepath(filename);
    FILE *file = fopen(filepath, "w+");
    for (int i = 0; i < 5; i++)
    {
        fprintf(file, "Product%lld: ", Plist[index[i]]);
        fprintf(file, "%d Yuan", target[i] * Price[index[i]]);
        fprintf(file, "\n");
    }
    fclose(file);
    system("pause");
}
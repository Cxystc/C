#include "initial.h"
#include "setting.h"
#include "allinclude.h"

int Savedays;
int daysetting(int flag)
{
    if (flag == 1)
    {
        FILE *f = fopen("./saved_days.txt", "w+");
        char *buffer;
        buffer = (char *)malloc(sizeof(char) * 5);
        memset(buffer, 0, sizeof(char) * 5);
        printf("请输入要保存的天数：\n");
        scanf("%d", &Savedays);
        itoa(Savedays, buffer, 10);
        fputs(buffer, f);
        fclose(f);
        printf("已保存!\n");
        return Savedays;
    }
    if (flag == 0)
    {
        FILE *f = fopen("./saved_days.txt", "a+");
        char *buffer;
        buffer = (char *)malloc(sizeof(char) * 5);
        memset(buffer, 0, sizeof(char) * 5);
        fgets(buffer, 5, f);
        if (buffer[0] == '\0')
        {
            printf("首次使用，请输入数据保存的天数：\n");
            scanf("%d", &Savedays);
            itoa(Savedays, buffer, 10);
            fputs(buffer, f);
            fclose(f);
            printf("已保存!\n");
            return Savedays;
        }
        else
        {
            Savedays = atoi(buffer);
            return Savedays;
        }
    }
}

long long ProductNumber[5] = {0};
long long *setting()
{
    FILE *f = fopen("./PNumber.txt", "a+");
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * 50);
    memset(buffer, 0, sizeof(char) * 50);
    fgets(buffer, 50, f);

    if (buffer[0] == '\0')
    { //如果没有数据就新加上数据
        printf("首次使用，请输入你的产品编号 \n");
        for (int i = 0; i < 5; i++)
        {
            scanf("%lld", &ProductNumber[i]);
            fputs(lltoa(ProductNumber[i], buffer, 10), f);
            fputc('\n', f);
        }
        fclose(f);
        return ProductNumber;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            ProductNumber[i] = atoll(buffer);
            memset(buffer, 0, sizeof(char) * 50);
            fgets(buffer, 50, f);
        }
        fclose(f);
        return ProductNumber;
    }
}

long long *resetting()
{
    FILE *f = fopen("./PNumber.txt", "w+");
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * 50);
    memset(buffer, 0, sizeof(char) * 50);
    fgets(buffer, 50, f);

    //如果没有数据就新加上数据
    printf("依次输入你的产品编号 \n");
    fflush(stdin);
    for (int i = 0; i < 5; i++)
    {
        scanf("%lld", &ProductNumber[i]);
        fputs(lltoa(ProductNumber[i], buffer, 10), f);
        fputc('\n', f);
    }
    fclose(f);
    printf("修改成功！\n");
    system("pause");
    return ProductNumber;
}

long long WorkersNumber[4] = {0};
long long *wsetting()
{
    FILE *f = fopen("./WNumber.txt", "a+");
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * 50);
    memset(buffer, 0, sizeof(char) * 50);
    fgets(buffer, 50, f);

    if (buffer[0] == '\0')
    { //如果没有数据就新加上数据
        printf("首次使用，请输入员工工号 : \n");
        for (int i = 0; i < 4; i++)
        {
            scanf("%lld", &WorkersNumber[i]);
            fputs(lltoa(WorkersNumber[i], buffer, 10), f);
            fputc('\n', f);
        }
        fclose(f);
        return WorkersNumber;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            WorkersNumber[i] = atoll(buffer);
            memset(buffer, 0, sizeof(char) * 50);
            fgets(buffer, 50, f);
        }
        fclose(f);
        return WorkersNumber;
    }
}

long long *rwsetting()
{
    FILE *f = fopen("./WNumber.txt", "w+");
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * 50);
    memset(buffer, 0, sizeof(char) * 50);
    fgets(buffer, 50, f);

    //新加上数据
    printf("依次输入员工工号: \n");
    fflush(stdin);
    for (int i = 0; i < 4; i++)
    {
        scanf("%lld", &WorkersNumber[i]);
        fputs(lltoa(WorkersNumber[i], buffer, 10), f);
        fputc('\n', f);
    }
    fclose(f);
    printf("修改成功！\n");
    system("pause");
    return WorkersNumber;
}

int Price[5];
int *Pricesetting()
{
    FILE *f = fopen("./Price.txt", "a+");
    char *buffer;
    buffer = (char *)malloc(sizeof(char) * 10);
    memset(buffer, 0, sizeof(char) * 10);
    fgets(buffer, 50, f);

    if (buffer[0] == '\0')
    {
        printf("首次使用请依次输入产品价格：\n");
        for(int i= 0 ; i< 5; i++)
        {
            int price;
            scanf("%d", &price);
            Price[i] = price;
            fputs(itoa(price,buffer,10),f);
            fputc('\n',f);
        }
        fclose(f);
        printf("保存成功！\n");
        system("pause");
        return Price;
    }
    
    else{
        for(int i= 0 ; i < 5;i++){
            Price[i] = atoi(buffer);
            memset(buffer,0,sizeof(buffer));
            fgets(buffer,50,f);
        }
        fclose(f);
        return Price;
    }
}
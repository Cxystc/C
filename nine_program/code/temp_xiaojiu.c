#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sale
{
    int product;
    int sales_amount;
};

struct Note
{
    int date;
    int staff;
    struct sale a[5];
    struct Note *next;
};

int n, i, j;
int main()
{
    struct Note *creat();
    void save(struct Note * p);
    struct Note *p3;
    p3 = creat();
    save(p3);
    void count();
    count();
    return 0;
}
//��ʼ������ �����������?
struct Note *creat()
{
    struct Note *head;
    struct Note *p1;
    struct Note *p2;
    n = 0; //ͳ�ƽڵ�ĸ���?
    p1 = (struct Note *)malloc(sizeof(struct Note));
    p2 = (struct Note *)malloc(sizeof(struct Note));
    if (NULL == p1)
    {
        return NULL;
    }
    if (NULL == p2)
    {
        return NULL;
    }
    printf("������ʱ�䡢Ա����ţ�?");
    scanf("%d,%d", &p1->date, &p1->staff);
    for (j = 0; j < 5; j++)
    {
        printf("��Ʒ%d�����۶�Ϊ��", j + 1);
        scanf("%d", &p1->a[j].sales_amount);
    }
    head = NULL;
    while (1)
    {
        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        p1 = (struct Note *)malloc(sizeof(struct Note));
        if (NULL == p1)
        {
            return NULL;
        }
        printf("������ʱ�䡢Ա����ţ�?");
        scanf("%d,%d", &p1->date, &p1->staff);
        if (p1->date == 0)
            break;
        for (j = 0; j < 5; j++)
        {
            printf("��Ʒ%d�����۶�Ϊ��", j + 1);
            scanf("%d", &p1->a[j].sales_amount);
        }
    }

    p2->next = NULL;
    return (head);
}

//������������д���ļ���
void save(struct Note *p)
{
    FILE *fp;
    struct Note *pt;
    pt = p;
    fp = fopen("D:\\My_code\\Cxystc-Python_selfteaching-1\\C\\nine_program\\data\\data.txt", "w"); //���ļ�
    if (fp == NULL)
    {
        printf("�ļ���ʧ��\n");
        return;
    }
    while (1) //�ѱ���д���ļ���
    {
        fprintf(fp, "%d\n%d\n", pt->date, pt->staff);
        for (j = 0; j < 5; j++)
        {
            fprintf(fp, "%d\n", pt->a[j].sales_amount);
        }
        printf("\nThe data have been saved in the file successfully!\n");
        if (pt->next == NULL)
        {
            break;
        }
        pt = pt->next;
    }
    fprintf(fp, "%d\n%d\n", 0, 0);
    fclose(fp);
    return;
}

//ͳ�Ʊ�������
void count()
{
    //�ȶ�ȡ�ļ��е�����
    FILE *f;
    f = fopen("D:\\My_code\\Cxystc-Python_selfteaching-1\\C\\nine_program\\data\\data.txt", "r"); //���ļ�

    struct Note *p;
    struct Note *head;
    p = (struct Note *)malloc(sizeof(struct Note));
    head = p;

    if (f == NULL)
    {
        printf("�޷��򿪴��ļ�\n");
        exit(0);
    }

    int date, staff;
    fscanf(f, "%d\n%d\n", &date, &staff);
    p->date = date;
    p->staff = staff;
    while (1)
    {
        for (int i = 0; i < 5; i++)
        {
            int a;
            fscanf(f, "%d\n", &a);
            p->a[i].sales_amount = a;
            p->a[i].product = i+1;
        }
        int date = 0;
        int staff = 0;
        fscanf(f, "%d\n%d\n", &date, &staff);
        if (date == 0)
        {
            p->next = NULL;
            break;
        }
        p->next = (struct Note *)malloc(sizeof(struct Note));
        p = p->next;
        p->date = date;
        p->staff = staff;
    }
    fclose(f);
    p = head;

    while (1)
    {
        printf("date:%d\nstaff:%d\n", p->date, p->staff);
        for (int i = 0; i < 5; i++)
        {
            printf("Number%d:%d\n", p->a[i].product, p->a[i].sales_amount);
        }
        if (p->next == NULL)
            break;
        p = p->next;
    }
    p = head;
    //�����ӡ��һ�¶�ȡ������?

    //ǰ��Ҫ��һ������ʷ�ļ�
    int time, temp, num;
ASK:
    printf("������Ҫ��ѯ��ʱ�䣺");
    scanf("%d", &time);
    int good[5] = {0};
    int ID[5] = {1, 2, 3, 4, 5};

    while (1) //Ҫ�����������ҵ�p->date == time��λ��
    {
        if (p->date == time)
        {
            for (int i = 0; i < 5; i++)
            {
                switch (p->a[i].product)
                {
                case 1:
                    good[0] += p->a[0].sales_amount;
                    break;
                case 2:
                    good[1] += p->a[1].sales_amount;
                    break;
                case 3:
                    good[2] += p->a[2].sales_amount;
                    break;
                case 4:
                    good[3] += p->a[3].sales_amount;
                    break;
                case 5:
                    good[4] += p->a[4].sales_amount;
                    break;
                }
            }
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4 - i; j++)
                    if (good[j] < good[j + 1])
                    {
                        num = ID[j];
                        ID[j] = ID[j + 1];
                        ID[j + 1] = num; //�����ʱ���Ʒ��IDҲ�ö�Ӧ
                        temp = good[j];
                        good[j] = good[j + 1];
                        good[j + 1] = temp;
                    }
            }
            break;
        }
        else
        {

            if (p->next == NULL)
            {
                printf("���Ҳ���������ڣ��ǲ���������ˣ�\n");
                goto ASK;
            }
            p = p->next;
            continue;
        }
    }
    printf("����������Ϊ%dʱ��ÿ�ֲ�Ʒ����Ա�����۶����\n", time);
    printf("��Ʒ���\t���۶�\n");
    for (i = 0; i < 5; i++)
    {
        printf("%4d\t\t\t%d\n", ID[i], good[i]);
    }
}

// double a=pow(16,-n)*(4/(8*n+1)-2/(8*n+4)-1/(8*n+5)-1/(8*n+6));
//counting proximate pi
#include <stdio.h>
#include <math.h>

void main()
{
    double precision;//声明精度
    double cunting_1(double prec,double n,double sum);//声明函数
    printf("please input the precision:");
    scanf("%f",&precision);
    printf("one");
    double n_,sum_ = cunting_1(precision,0,0);//调用函数
    printf("two");
    printf("times:%d\nsum:%lf\n",n_,sum_);
}

//函数部分
double cunting_1(double prec,double n,double sum)//计算Ak的值；把Ak加起来；判断；输出n(默认为零)；输入精度
{   
    double Ak=pow(16,-n)*(4/(8*n+1)-2/(8*n+4)-1/(8*n+5)-1/(8*n+6));
    if (Ak >= (int)(prec))
        {   
            sum += Ak;
            n++;//记录n的大小，就是项数
            cunting_1(prec,n,sum);
        }
    else if(Ak < (int)(prec))
   { 
    printf("n:%f\nsum:%f");
    return n,sum;
    }
}


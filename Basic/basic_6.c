//火车相遇问题
#include <stdio.h>
int count(float speed1,float speed2,float len1,float len2)
{
    float speed3 = speed1 + speed2 ;//如果定义int，int/int 还是int
    float len3 = len1 + len2 ;
    float t = len3/speed3 ;//double float就可以输出小数 到这里一步如果len3和speed3还是int类型那么t就会是int类型，空间不够直接舍弃小数，不会四舍五入，只是取整
    printf("The time is : %.3f\n",t);
    return t ;
}

int main()
{
    count(15,12,150,200);
    float dd = 350.0 / 27 ;//没有定义的情况下350就是int，必须用350.0
    printf("%.3f\n",dd);
    return 0 ;
}
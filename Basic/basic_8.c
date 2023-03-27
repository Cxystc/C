//基本的运算
#include <stdio.h>
#include <stdlib.h>//rand()    RAND_MAX
#include <math.h>//
int main()//注意关键字不要打错

#define pi 3.1415926 //没有等于号，这是预处理器干的活，编译器不知道有pi的存在，更加没有给常量pi分配内存空间（这是定义常量的一种方法，但是不推荐）
{
    double x =  2,y = 8;
    printf("2 ^ 8 : %.2f \n", pow(x,y));//2**8
    printf("round(123.123) :%.2f \n", round(123.123));//四舍五入//可以int(round(123.123))
    printf("floor(3.14) :%.2f \n",floor(3.14));//上取整
    printf("ceil(3.14) :%.2f \n",ceil(3.14));//下取整
    printf("sqrt(5) :%.2f \n",sqrt(5));//开平方
    
    int r0 = rand();//在0——RAND_MAX中取整
    int r1 = rand() % 100;//在0 —— 99 中取整 
    double r2 = 0.1 + 0.1 *rand()/RAND_MAX;//结果就是0——1 的随机浮点数 * 0.1//整体上看就是0.1——0.2的随机浮点数
    printf("r0 : %d r1 : %d r2 : %.2f " ,r0,r1,r2);//注意一定要用双引号
    printf("RAND_MAX : %x \n",RAND_MAX);//7fff

    int weight;
    float height;
    printf("Please input your weight(kg) and height(cm):(use\",\"to spilt two numbers)\n");
    scanf("%d,%f",&weight,&height);
    printf("Your height is %.2fcm ,and your weight is %dkg!",height,weight);
    
    //常量
    const float ipi = 3.1415926;
    // ipi = ipi * 3;//error: assignment of read-only variable 'ipi'常量是不能修改的
    printf("Area of circle :%.2f\n",ipi *2*2);
    printf("Area of circle :%.2f\n",pi * pow(2,2));
    return;
}
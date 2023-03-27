#include <stdio.h>
#include <math.h>
//牛顿迭代法求函数的近似根

int main()
{
   double x = 0, x1 = 1.5;
   double p = pow(10, -10); //精度
   int n = 0;               //初始值

   while (fabs(x - x1) > p) // fabs是双精度浮点数的绝对值 abs只能计算int类型的数据
   {
      x = x1;
      double fd1 = 6 * pow(x, 2) - 8 * x + 3;
      double f1 = 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
      x1 = x1 - f1 / fd1; //赋值语句从右往左
      n += 1;
      printf("%f %d\n", x1, n);
   }

   return 0;
}
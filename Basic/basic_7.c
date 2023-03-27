#include <stdio.h>
//控制温度的转化
int main()
{   int tempertransger (float);
    int a = 41;
    tempertransger(a);
}


int tempertransger (float Celsius)
{
    float F = 9.0 * Celsius / 5.0  + 32.0 ;
    printf("The Fahrenheit temperter now is :% .2f F \n",F);
    return 0;
}

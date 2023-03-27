//*库洛题目
#include <string.h>
#include <math.h>
#include <stdio.h>

int main ()
{
    float Distance(float x1, float y1, float x2, float y2, float x3, float y3);
    //输入三个点
    float x1,y1,x2,y2,x3,y3;  
    printf("Please input the  point (use ' ' to split tow number):\n");
    scanf("%f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3);
    float distance = Distance(x1,y1,x2,y2,x3,y3);
    printf("%.2lf",distance);
    return 0;

}
float Distance (float x1, float y1, float x2, float y2, float x3, float y3)
{

    float Len1 = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    float Len2 = sqrt(pow(x2-x3,2)+pow(y2-y3,2));
    float Len3 = sqrt(pow(x1-x3,2)+pow(y1-y3,2));
    float LEN = Len1 + Len2 + Len3;
    return LEN;
}
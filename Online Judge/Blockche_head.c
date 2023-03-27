#include <stdio.h>
#include <string.h>
#include <math.h>


int main() {
    double  pi = acos(-1);
    double dec = (pi/180);
    double a ,x;
    scanf("%lf",&a);
    scanf("%lf",&x);
    double y = x*cos(a*dec);
    double R = y * tan(a*dec/2);
    double size_ = pi*R*2;
    printf("%.8lf",size_);
}
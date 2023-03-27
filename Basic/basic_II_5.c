#include <stdio.h>
int main()
{   int a = 62707;
    int b = 2896;
    int c;
    c += (a % 10) * 100000;
    c += (a/10)%10 * 10000;
    c += (a/100)%10 * 1000;
    c += (b%10) *100;
    c += (b/10) %10 *10;
    c += (b/100) %10 ;
    printf("a=%d,b=%d,c=%d\n", a, b, c);
}


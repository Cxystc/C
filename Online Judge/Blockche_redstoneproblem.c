#include <stdio.h>
#include <math.h>

int main()
{
    long long n;
    scanf("%lld",&n); 
    long long max = n / 18 * 16 + ((n%18 < 15 ) ? n%18 : 15 );
    printf("%lld", max);
}
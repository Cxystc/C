#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s, t;
    long long int n = 0 ; 
    scanf("%d %d", &s, &t);
    for (int i = 0; i <= s; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int z = 0; z <= j; z++)
            {   
                if (i*j*z> t)break;
                if (i+j+z <= s ) n ++ ; 
            }
        }
    }
    printf("%d",n);
}
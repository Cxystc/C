#include <string.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i, *p, arr[4] = {1, 2, 3, 4}; // arr就是数组名，本事就相当于一个pointer
    // p = arr;
    // p = &arr[0];
    p = (arr + 0);//此三者等效
    for (i = 0; i < 4; i++, p++)
    {
        printf("p%d = %d \n", i + 1, *p);
    }
}
#include <stdio.h>
int main ()//已经打错很多次了
{
    char a ;
    int x,y;
    int func_1 (int x , int y);
    int func_2 (int x , int y);

    printf("Input your character: \n");
    a = getchar();
    switch (a)
    {
        case 'a': x = 10,y = 10;//case后面是单引号
        break;
        case 'b': x =20,y = 20;
        break;
        default : printf("Your input is invalid");
    }
    printf("x * y = %d\n",func_1(x,y));
    printf("x + y = %d \n",func_2(x,y));
    return 0;
}


int func_1(int x ,int y )
{   
    int z ;
    return z = x * y ;
}

int func_2(int x ,int y )
{
    int z; 
    z = x + y ;
    return z;
}
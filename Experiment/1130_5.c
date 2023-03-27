#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *result;
    result = ( char *) malloc (10);
    gets(result);
    char each[100] = {'\0'};
    int LEN = 10;
    do
    {
        gets(each);
        LEN += strlen(each);
        realloc(result, LEN);//realloc 必须现有calloc或者malloc ， 而且LEN是新长度
        strcat(result, each);
    } while (strlen(each) > 0);
    printf("%s ", result);
}
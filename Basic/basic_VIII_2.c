#include <stdio.h>
#include <string.h>
int main()
{
    // hgaslfjsd123521djifhjsSBJASDDDFJIHDKDAEBF
    char a[] = "hgaslfjsd\0";
    char b[] = "123521djifhjs\0";
    char c[] = "SBJASDDDFJIHDKDAEBF\0";
    printf("%s \n%s \n%s \n " ,a,b,c);
    char d[100] = {0};
    int lena = 0, lenb = 0, lenc = 0;
    while (1)
    {
        lena += 1;
        if (a[lena] == '\0')
            break;
    }
    while (1)
    {
        lenb += 1;
        if (b[lenb] == '\0')
            break;
    }
    while (1)
    {
        lenc += 1;
        if (c[lenc] == '\0')
            break;
    }
    int o = 0; 
    for (int i = 0; i < lena; i++)
    {
        d[o] = a[i];
        o++;
    }
    for (int i = 0; i < lenb; i++)
    {
        d[o] = b[i];
        o++;
    }
    for (int i = 0; i < lenc; i++)
    {
        d[o] = c[i];
        o++;
    }
    for (int i = 0; i < 45; i++)
    {
        printf("%c", d[i]);
    }
}
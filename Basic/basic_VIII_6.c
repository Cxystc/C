#include <stdio.h>
#include <string.h> 
//实现strcmp功能： 以及其测试程序
int Strcmp( char * a , char * b ) { //a > b -> 1 ; a < b -> -1 ; a == b -> 0 ; 
    int an = 0 ; // a的长度
    int bn = 0 ; // b的长度
    while (a[an] != '\0'){
        an ++ ; 
    }
    while (b[bn] != '\0'){
        bn ++ ; 
    }
    for (int i = 0 ;i < ((an > bn) ? bn : an);i++){
        if (a[i] > b [i] ) return 1 ; 
        else if (a[i] < b [i] ) return -1 ; 
    }
    if (an == bn ) return 0 ; 
    if (an > bn) //an还有但是bn结束了此时就是an大返回1
    {
        return 1; 
    }
    if (an < bn) 
    {
        return -1; 
    }
}

int main() {
    char a1[10] = "abcdefg";
    char a2[10] = "abcdefg";
    char b1[10] = "abcdefg";
    char b2[10] = "abcDEFG";
    char c1[10] = "abcdefg";
    char c2[10] = "abc";

    int resulta = Strcmp(a1,a2);//应当为0 
    int resultb = Strcmp(b1,b2);//应当为-1 
    int resultc = Strcmp(c1,c2);//应当为1 

    if (resulta == strcmp (a1,a2)) printf("right\n");
    if (resultb == strcmp (b1,b2))printf("right\n");
    if (resultc == strcmp (c1,c2))printf("right\n");
    return 0 ; 
}
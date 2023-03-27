//Nvidia : RTX 
//AMD : RX 
#include <stdio.h>
#include <string.h>
int main() {
    char s[9] = {'0'};//保证所有
    char type[5] = {'0'}; //数字的下标
    scanf("%s",s);
    if(s[1] == 'X'){//AMD:
        printf("AMD\n");
        for (int i = 2; i <= 5 ;i++){
            type[i-2] = s[i]; 
        }
        printf("%s\n",type);
    if (s[6] != '\0'){
        printf("Yes");
    }
    else printf("No");
    }

    if(s[1] == 'T'){//Nvidia
        printf("Nvidia\n");
        for ( int i =3 ; i <=6 ;i++){
            type[i-3] = s[i];
        }
        printf("%s\n",type);
    if (s[7] != '\0'){
        printf("Yes");
    }
    else printf("No");
    }
}
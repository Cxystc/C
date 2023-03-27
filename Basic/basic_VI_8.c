#include <stdio.h>
#include <string.h>

int main (){
    int T ; 
    scanf("%d",&T);
    
    for (int i  =0 ; i < T ; i++){
    int times ;
        char *s; 
        char *k;
        scanf("%s",s);
        scanf("%s",k);
        for(int j = 0 ; j < strlen(s); j++){
                int y = 0 ; 
            for (int z = j ; z < strlen(k);z++){
                if (s[z] == k[z]) {
                    y += 1 ; 
                    if ( y == strlen (k))times += 1 ; 
                    continue;
                }
                else break; 
            }
        }
    printf("%d",times);
    }
}
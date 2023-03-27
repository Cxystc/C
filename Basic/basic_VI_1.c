//加密打字机
#include <string.h>
#include <stdio.h>

int main (){
    char pw[20]; 
    char cpw[20]; 
    scanf("%s",pw);
    for ( int i = 0 ; i < 20 ; i ++ ){
       if (pw[i] >= 'A' && pw[i] <= 'Z'){
         if (pw[i] == '#') break ; 
        else if (pw[i] >= 'W') {
            cpw[i] = pw[i] - 'A' + 4;
        }
        cpw[i] = pw[i] + 4; 
       }

       if (pw[i] >= 'a' && pw[i] <= 'z'){
         if (pw[i] == '#') break ; 
        else if (pw[i] >= 'w') {
            cpw[i] = pw[i] - 'a' + 4;
        }
        cpw[i] = pw[i] + 4; 
       }
    }
    
    printf("%s\n",cpw);

}
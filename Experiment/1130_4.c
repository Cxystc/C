#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
    char argv_ [argc][100] ;

    for (int i = 0 ; i <argc ; i++){
        strcpy(argv_[i],argv[i]);
    }
    for ( int i = 0 ; i < argc - 1 ; i++){
        // printf("i:%d ",i);
        for ( int j = 0 ; j < argc - 1 - i ; j ++){
            // printf("j:%d ",j);
            if(strcmp(argv_[j],argv_[j+1]) == 1 ){
                char temp[100]; 
                strcpy(temp,argv_[j+1]);
                strcpy(argv_[j+1],argv_[j]);
                strcpy(argv_[j],temp);
            }
        }
    }
    for ( int i = 0 ; i < argc ; i ++){
        printf("%s \n",argv_[i]);
    }

}
//二维数组传参训练
#include <stdio.h>

// int main (){
//     int a[10][10] = {0} ;
//     int Creat(int ** list ,int n  );
//     int Print(int ** list , int n );//n就是数组的行长
//     Creat((int**)a, 10);
//     Print((int**)a , 10);
// }

// int Creat(int ** list,int n ){
//     for (int i = 0 ; i < 10 ; i++ ){
//         for ( int j =0 ; j < 10 ; j ++){
//             *(list  + n * i + j ) = n*i + j ;
//         }
//     }
// }
// int Print(int **list,int n) {
//     for (int i = 0 ; i < 10 ; i++){
//         for ( int j= 0 ; j < 10 ; j++){
//             printf("%d " ,*(list + n * i + j));
//         }
//     }
// }

// int main ()
// {
//     int a[10][10];
//     int Print(int(*p)[10], int n);
//     int Creat(int(*p)[10], int n);
//     Creat(a, 10);//直接写数组名
//     Print(a, 10);
// }
// int Creat( int (*p)[10] , int n ) {
//     for ( int i = 0 ; i < 10 ; i ++){
//         for ( int j =0 ; j <10 ; j ++){
//             *(*(p+i)+ j ) = i*n + j ;
//         }
//     }
// }

// int Print(int (*p)[10], int n)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             printf("%d ", *((int *)p + n * i + j));
//         }
//         printf("\n");
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             printf("%d ", *((int *)*(p + i) + j));//这种办法不行
//         }
//         printf("\n");
//     }
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             printf("%d ", *(p[i] + j));
//         }
//         printf("\n");
//     }
// }

int main()
{
    int Creat(int a[10][10], int n);
    int Print(int a[10][10], int n);
    int a[10][10] = {0};
    Creat(a, 10);
    Print(a, 10);
}

int Creat ( int a[10][10] , int n ){
    for (int i = 0 ; i < 3 ; i ++){
        for ( int j = 0 ; j < 10 ; j ++){
            *(*(a+i)+j) = i * n + j ; 
        }
    }
    for (int i = 3 ; i < 6 ; i ++){
        for ( int j= 0 ; j < 10 ; j ++)  {
            *(a[i] + j ) = i * n + j ; 
        }
    }
    for ( int i = 6 ; i < 10 ; i++){
        for (int j = 0 ; j < 10 ; j ++){
            *((int *)a + n* i + j ) = i * n + j ; 
        }
    }
}

int Print( int a[10][10] , int n ) {
    for ( int i = 0 ; i < 10 ; i ++ ){
        for ( int j = 0 ; j < 10 ; j++ ) {
            printf("%d ", *((int *) a + n* i + j ));
        }
        printf( "\n" ) ;
    }
}
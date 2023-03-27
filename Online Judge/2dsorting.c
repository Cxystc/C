#include <stdio.h>

int insert_sort(int *a, int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        int i = j + 1;
        int temp = a[i];
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int N = 0; N < n; N++)
    {
        int row = 0, coloum = 0;
        printf("Please input row and column : \n");
        scanf("%d %d", &row, &coloum);
        int a[row * coloum];
        int b[row][coloum];
        for (int i = 0; i < row * coloum; i++)
        {
            scanf("%d", &a[i]);
        }

        //排a[i]
        insert_sort(a, row * coloum);
        int t = 0 ; 
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < coloum; j++)
            {
                b[i][j] = a[t];
                t ++ ; 
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }
    }
}
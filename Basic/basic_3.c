#include <stdio.h>
#include <string.h>
// DO NOT edit this line
void turningClockwise(char a[N][N])
{

  char q;
  q = a[0][N - 2];
  char w;
  w = a[0][N - 1];
  char e;
  e = [N - 1][0];
  char r;
  r = [N - 1][1];
  // Add your code here
  for (int i = N - 1; i >= 0; i--)
    a[0][i] = a[0][i - 1];
  for (int i = 0; i < N; i++)
    a[N - 1][i] = a[N - 1][i + 1];

  a[0][N - 1] = w;
  a[N - 1][0] = e;

  for (int i = N - 1; i >= 0; i--)
    a[i][N - 1] = a[i - 1][N - 1];
  for (int i = 0; i < N; i++)
    a[0][i] = a[0][i + 1];
}
#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y);

bool cmp(int x, int y)
{
	return x < y;
}

int main()
{
	int n;								//多少组（times）
	int j;								
	scanf("%d", &n);
	int num[405] = {0};
	for (j = 1; j <= n; j++)
	{
		int row;
		int column;
		scanf("%d %d", &row, &column);	//对于每一组的参数row and colum
		int sum = row * column;          //总数

		int i;
		for (i = 1; i <= sum; i++)
		{
			scanf("%d", &num[i]);
		}
		sort(num + 1, num + sum + 1, cmp);
		for (i = 1; i <= sum; i++)
		{
			printf("%d ", num[i]);
			if (i % column == 0)
			{
				printf("\n");
			}
		}
	}
	return 0;
}

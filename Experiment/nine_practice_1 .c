#include <stdio.h>
#include <stdlib.h>

int month_day(int year, int yearday, int *pmonth, int *pday)
{ // Add your code here
	int b = 0, all = 365;
	int mon_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0 && year % 100 == 0 || year % 400 == 0)
	{
		mon_day[1] = 29;
		all = 366;
	}
	if (yearday > 367)
		return 0;
	else
	{
		for (int i = 1; i <= 12; i++)
		{
			if (yearday < mon_day[i - 1])
			{
				pmonth = &i;
				pday = &yearday;
				break;
			}
			else
			{
				yearday -= mon_day[i - 1];
				if (yearday <= mon_day[i])
					pday = &yearday;
			}
		}
		printf("%d %d " , *pmonth, *pday);
		return 1;
	}
}

int main()
{
	int *pmonth;
	int *pday ;
	month_day(2010,27,pmonth,pday);
}
#include <stdio.h>

int mdays[][12] = 
{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

int isleap(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int dayofyear(int y, int m, int d)
{
	int i;
	int days = d;

	i = 1;
	while (i < m)
	{
		days += mdays[isleap(y)][i-1];
		i++;
	}
	return days;
}

int main()
{
	int year, month, day;
	int retry;
	do {
		printf("year: "); scanf("%d", &year);
		printf("month: "); scanf("%d", &month);
		printf("day: "); scanf("%d", &day);
		printf("year:%d days after: %d\n", year, dayofyear(year, month, day));
		printf("retry? enter 1");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}

#include <stdio.h>
typedef struct {
	int y;
	int m;
	int d;
} Date;

Date Before(Date x, int n);
Date After(Date x, int n);

static int mdays[][13] =
{
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isleap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

Date DateOf(int y, int m, int d)
{
	Date temp;

	temp.y = y;
	temp.m = m;
	temp.d = d;

	return temp;
}

Date After(Date x, int n)
{
	if (n < 0)
		return Before(x, -n);

	x.d += n;

	while (x.d > mdays[isleap(x.y)][x.m - 1])
	{
		x.d -= mdays[isleap(x.y)][x.m - 1];
		if (++x.m > 12)
		{
			x.y++;
			x.m = 1;
		}
	}
	return x;
}

Date Before(Date x, int n)
{
	if (n < 0)
		return After(x, -n);

	x.d -= n;

	while (x.d < 1)
	{
		if (--x.m < 1)
		{
			x.y--;
			x.m = 12;
		}
		x.d += mdays[isleap(x.y)][x.m - 1];
	}
	return x;
}

int Print(Date x)
{
	int y = x.y;
	int m = x.m;
	int d = x.d;

//제라의 공식
	char *ws[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	if (m == 1 || m == 2)
	{
		y--;
		m += 12;
	}
	printf("%04dyear %02dmonth %02dday(%s)", x.y, x.m, x.d, ws[(y+y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7]);
}

int main(void)
{
	int n;
	int y, m, d;
	Date x;

	printf("Enter the date\n");
	printf("Year: "); scanf("%d", &y);
	printf("Month: "); scanf("%d", &m);
	printf("Day: "); scanf("%d", &d);

	x = DateOf(y, m, d);

	printf("며칠 앞 / 뒤의 날짜를 구할까요? ");
	scanf("%d", &n);

	printf("%d After: ", n); Print(After(x, n)); puts("");
	printf("%d Before: ", n); Print(Before(x, n)); puts("");

	return 0;
}

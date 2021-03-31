#include <stdio.h>

void recur(int n)
{
Top :
	if (n > 0)
	{
		recur(n-1);
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}
}

int main()
{
	recur(4);

	return 0;
}

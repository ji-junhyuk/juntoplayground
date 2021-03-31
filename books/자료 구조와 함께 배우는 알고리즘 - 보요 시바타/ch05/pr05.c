// 1 2 1 3 1 2 4
#include "../ch04/ex01_IntStack.h"
#include <stdio.h>
void recur(int n)
{
	int sw = 0;
	IntStack nstk, sstk;

	Initialize(&nstk, 100);
	Initialize(&sstk, 100);

	while (1)
	{
		if (n > 0)
		{
			Push(&nstk, n);
			Push(&sstk, sw);

			if (sw == 0)
				n = n - 1;
			else if (sw == 1)
			{
				n = n - 2;
				sw = 0;
			}
			continue;
		}
		do 
		{
			Pop(&nstk, &n);
			Pop(&sstk, &sw);
			sw++;

			if (sw == 2)
			{
				printf("%d\n", n);
				if (IsEmpty(&nstk))
				{
					Terminate(&nstk);
					Terminate(&sstk);

					return ;
				}
			}
		} while (sw == 2);
	}
}

/*
void recur(int n)
{
	if (n > 0)
	{
		recur(n-1);
		recur(n-2);
		printf("%d\n", n);
	}
}
*/
int main()
{
	recur(4);

	return 0;
}

#include <stdio.h>
#include "../ch04/ex01_IntStack.h"

void move(int no, int x, int y)
{
	int sw = 0;
	IntStack xstk, ystk, sstk;

	Initailize(&xstk, 100);
	Initailize(&ystk, 100);
	Initailize(&sstk, 100);

	while (1)
	{
		if (sw == 0 && no > 1)
		{
			Push(&xstk, x);
			Push(&ystk, y);
			Push(&sstk, sw);
			no = no - 1;
			y = 6 - x - y;
			continue;
		}

		printf("%d, %d, %d\n", no, x, y);

		if (sw == 1 && no > 1)
		{
			Push(&xstk, x);
			Push(&ystk, y);
			Push(&sstk, sw);
			no = no - 1;
			x = 6 - x - y;
			if (++sw == 2) sw = 0;
			continue;
		}
		do 
		{
			if (IsEmpty(&xstk))
				return ;
			Pop(&xstk, &x);
			Pop(&ystk, &y);
			Pop(&sstk, &sw);
			sw++;
			no++;
		} while (sw == 2);
	}



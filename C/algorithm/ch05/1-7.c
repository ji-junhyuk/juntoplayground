//
// Created by junto on 21. 1. 18..
//

#include <stdio.h>
#include "IntStack.h"

void move(int no, int x, int y)
{
	int sw = 0;
	IntStack xstk, ystk, sstk;

	Initialize(&xstk, 100);
	Initialize(&ystk, 100);
	Initialize(&sstk, 100);

	while (1) {
		if (sw == 0 && no > 1) {
			Push(&xstk, x);
			Push(&ystk, y);
			Push(&sstk, sw);
			no = no - 1;
			y = 6 - x - y;
			continue;
		}

		printf("원반[%d]를 %d 기둥에서 %d 기둥으로 이동\n", no, x, y);

		if (sw == 1 && no > 1) {
			Push(&xstk, x);
			Push(&ystk, y);
			Push(&sstk, sw);
			no = no - 1;
			x = 6 - x - y;
			if (++sw == 2) sw = 0;
			continue;
		}
		do {
			if (IsEmpty(&xstk))
				return;
			Pop(&xstk, &x);
			Pop(&ystk, &y);
			Pop(&sstk, &sw);
			sw++;
			no++;
		} while (sw == 2);
	}

	Terminate(&xstk);
	Terminate(&ystk);
	Terminate(&sstk);
}

int main(void)
{
	int n;		/* 원반의 개수 */

	printf("하노이 탑\n원반 개수 : ");
	scanf("%d", &n);

	move(n, 1, 3);

	return 0;
}


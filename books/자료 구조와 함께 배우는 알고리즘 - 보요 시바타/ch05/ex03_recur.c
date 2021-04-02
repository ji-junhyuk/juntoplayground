#include <stdio.h>
void recur(int n)
{
	if (n > 0)
	{
		recur(n-1);
		printf("%d\n", n);
		recur(n-2);
	}
}

int main()
{
	int x;
	x = 4;
	recur(4);

	return 0;
}
/*
   r(3) p(4) r(2)
   r(2) p(3) r(1) p(4) r(1) p(2) r(0)
   r(1) p(2) r(0) p(1) p(3) r(0) p(1) p(2)
   p(1) p(2) (p3) p(1) p(4) p(1) p(2)
*/
/*
   n = 0; 출력 없음
   n = 1; p(1)
   n = 2; r(1)p(2) -> p(1)p(2)
   n = 3; r(2)p(3)r(1) -> p(1)p(2)p(3)p(1)
   n = 4; r(3)p(4)r(2) -> p(1)p(2)p(3)p(1)p(4)(p1)(p2)
*/

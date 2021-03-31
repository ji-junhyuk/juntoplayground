#include <stdio.h>
#include "../ch04/ex01_IntStack.h"

void recur(int n)
{
	IntStack stk;
	Initialize(&stk, 8);

Top:
	if (n > 0)
	{
		Push(&stk, n);
		n = n - 1;
		goto Top;
	}
	if (!IsEmpty(&stk))
	{
		Pop(&stk, &n);
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}
	Terminate(&stk);
}

int main()
{
	recur(4);

	return 0;
}

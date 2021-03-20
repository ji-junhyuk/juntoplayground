#include <stdio.h>
void print(int n, ...)
{
	int *ap = &n+1;
	if (n == 1)
		printf("%d\n", ap[0]);
	else if (n == 2)
		printf("%d %d\n", ap[0], ap[1]);
	else if (n == 3)
		printf("%d %d %d\n", ap[0], ap[1], ap[2]);
	else
		puts("인자에 개수가 1~3개까지 출력 가능합니다.");
}
void main()
{
	int a = 10, b = 20, c = 30;

	print(1, a);
	print(2, a, b);
	print(3, a, b, c);
}

#include <stdio.h>
void print(int n, ...)
{
	if (n == 1)
		printf("%d\n", *(&n+1));
	else if (n == 2)
		printf("%d %d\n", *(&n+1), *(&n+2));
	else if (n == 3)
		printf("%d %d %d\n", *(&n+1), *(&n+2), *(&n+3));
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

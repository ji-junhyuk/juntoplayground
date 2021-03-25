#include <stdio.h>
void main()
{
	int n, k;

	scanf("%d", &n);

	k = 0;

	while (n)
	{
		n /= 10;
		k++;
	}
		printf("그 수는 %d자리수 입니다.", k);
}

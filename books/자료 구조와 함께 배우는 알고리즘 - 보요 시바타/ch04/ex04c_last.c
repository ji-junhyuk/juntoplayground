#include <stdio.h>
#define N 10

int main()
{
	int i;
	int a[N];
	int cnt = 0;
	int retry;
	puts("enter the number: ");
	do {
		printf("%dth number: ", cnt + 1);
		scanf("%d", &a[cnt++ %N]);
		printf("retry: 1\n");
		scanf("%d", &retry);
	} while (retry == 1);
	i = cnt - N;
	if (i < 0)
		i = 0;
	
	while (i < cnt)
	{
		printf("%2dth number = %d\n", i+1, a[i % N]);
		i++;
	}
	return 0;
}

#include <stdio.h>
void main()
{
	int n1, n2;
	double d;

	scanf("%d %d", &n1, &n2);

	if (n2)
		d = (double)n1/n2;
	else
	{
		printf("분모는 0이 될 수 없습니다");
		return ;
	}
	printf("%lf", d);
}

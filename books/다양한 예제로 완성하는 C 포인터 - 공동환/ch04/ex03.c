#include <stdio.h>
int main()
{
	char carr[3] = {'A', 'B', 'C'};
	char *cp = carr;

	printf("%ld %ld\n", sizeof(cp), sizeof(carr));
	cp = NULL;
//	carr = NULL; 배열은 상수.
}

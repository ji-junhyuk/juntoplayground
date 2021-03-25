#include <stdio.h>

int main()
{
	int number;
	do {
		scanf("%d", &number);
	} while (number < 10 || number > 99);

	printf("number: %d\n", number);

	return 0;
}

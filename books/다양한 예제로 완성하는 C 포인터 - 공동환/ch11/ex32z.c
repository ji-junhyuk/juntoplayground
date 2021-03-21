#include <stdio.h>
#include <stdlib.h>

void main()
{
	char arr[100];
	int numCount[26] = {0};
       	int i;

	i = 0;
	while (i < 100)
	{
		arr[i++] = rand() % 26 + 'A';
	}

	i = 0;
	while (i < 100)
	{
		printf("%3c", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
		i++;
	}

	i = 0;
	while (i < 100)
	{
		numCount[arr[i]-'A']++;
		i++;
	}

	i = 0;
	while (i < 26)
	{
		printf("%c : %d\n", i+'A', numCount[i]);
		i++;
	}
}		

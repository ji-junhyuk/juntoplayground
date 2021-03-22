#include <stdio.h>
#include <string.h>
void main()
{
	char arr[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	char temp[10];

	int i;

	memcpy(temp, arr, sizeof(char)*10);

	i = 0;
	while (i < 10)
	{
		printf("%c %c\n", arr[i], temp[i]);
		i++;
	}

	memcpy(temp, arr+5, sizeof(char) * 5);
	memcpy(temp+5, arr, sizeof(char) * 5);

	i = 0;
	while (i < 10)
	{
		printf("%c %c\n", arr[i], temp[i]);
		i++;
	}
}

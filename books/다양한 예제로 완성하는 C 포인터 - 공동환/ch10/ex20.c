#include <stdio.h>
void strprint(const char *str)
{
	int i;
	for (i = 0; str[i]; i++)
		printf("%c", str[i]);
	puts("");
}

void arrprint(const int *arr)
{
	int i;
	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	puts("");
}

void main()
{
	char *str1 = "ABCDEF";
	int arr1[5] = {1, 2, 3, 4, 5};

	strprint(str1);
	arrprint(arr1);
}

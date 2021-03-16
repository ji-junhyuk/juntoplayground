#include <stdio.h>
int main()
{
	char *str = "ABCDEF";
	char arr[] = "ABCDEF";

	printf("%ld %ld\n", sizeof(str), sizeof(arr));
	printf("%c %c\n", str[0], arr[0]);
	printf("%c %c\n", *str, *arr);
}

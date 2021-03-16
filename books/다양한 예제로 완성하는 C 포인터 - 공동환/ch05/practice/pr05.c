#include <stdio.h>
int main()
{
	char *str = "ABCDEF";
	char arr[] = "SSSSSS";

	arr[0] = 'Z';
	arr[1] = 'Z';

	str = arr;
//	arr = str;
	printf("%s\n", str);
	printf("%s\n", arr);
	printf("%c %c\n", arr[0], arr[1]);
}

#include <stdio.h>
int main()
{
	char arr[20] = "ABCDEF";

	printf("%c %c %c\n", arr[0], arr[1], arr[2]);
	printf("%s\n", arr);
	printf("%s\n", arr+1);
	puts(arr+2);
	puts(arr+3);
}

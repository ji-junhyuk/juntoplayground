#include <stdio.h>
int main()
{
	char carr2[2][2] = {'A', 'B', 'C', 'D'};
	char (*ap)[2] = (char(*)[2]) carr2;

	printf("%c %c %c %c\n", carr2[0][0], carr2[0][1], carr2[1][0], carr2[1][1]);
	printf("%c %c %c %c\n", ap[0][0], ap[0][1], ap[1][0], ap[1][1]);
}

#include <stdio.h>
int main()
{
	char carr[12] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
	char (*ap1)[4] = (char (*)[4])carr;
	char (*ap2)[3] = (char (*)[3])carr;
	char (*ap3)[2][3] = (char (*)[2][3])carr;

	printf("%c %c %c %c %c %c %c %c %c %c %c %c\n", ap1[0][0], ap1[0][1], ap1[0][2], ap1[0][3], ap1[1][0], ap1[1][1], ap1[1][2], ap1[1][3], ap1[2][0], ap1[2][1], ap1[2][2], ap1[2][3]);
	printf("%c %c %c %c %c %c %c %c %c %c %c %c\n", ap2[0][0], ap2[0][1], ap1[0][2], ap2[1][0], ap2[1][1], ap2[1][2], ap2[2][0], ap2[2][1], ap2[2][2], ap2[3][0], ap2[3][1], ap2[3][2]);
	printf("%c %c %c %c %c %c %c %c %c %c %c %c\n", ap3[0][0][0], ap3[0][0][1], ap3[0][0][2], ap3[0][1][0], ap3[0][1][1], ap3[0][1][2], ap3[1][0][0], ap3[1][0][1], ap3[1][0][2], ap3[1][1][0], ap3[1][1][1], ap3[1][1][2]);
}

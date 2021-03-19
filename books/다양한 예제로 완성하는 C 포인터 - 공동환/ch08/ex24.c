#include <stdio.h>
void func(int ap[][3])//void func(char (*ap)[3])
{
	printf("%d %d %d %d %d %d\n", ap[0][0], ap[0][1], ap[0][2], ap[1][0], ap[1][1], ap[1][2]);
}

void main()
{
	int iarr[2][3] = {{'A', 'B', 'C'}, {1, 2, '3'}};

	func(iarr);
}

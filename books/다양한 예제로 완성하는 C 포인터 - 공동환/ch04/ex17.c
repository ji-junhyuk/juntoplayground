#include <stdio.h>
int main()
{
	char carr[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};

	char (*ap1)[4] = (char (*)[4])carr;
	char (*ap2)[3] = (char (*)[3])carr;
	char (*ap3)[2][3] = (char (*)[2][3])carr;

	printf("%ld %ld %ld %ld\n", sizeof(carr), sizeof(ap1), sizeof(ap2), sizeof(ap3));
}

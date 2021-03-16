#include <stdio.h>
int main()
{
	char carr[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
	int *ap = (int *)carr;

	printf("%c %c %c %c\n", carr[0], carr[1], carr[2], carr[3]);
	printf("%c %c %c %c\n", carr[4], carr[5], carr[6], carr[7]);
	printf("%c %c %c %c\n", carr[8], carr[9], carr[10], carr[11]);
	printf("%c %c %c %c\n", carr[12], carr[13], carr[14], carr[15]);
	printf("%d %d %d %d\n", ap[0], ap[1], ap[2], ap[3]);
}

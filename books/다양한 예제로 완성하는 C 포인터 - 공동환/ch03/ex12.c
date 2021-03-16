#include <stdio.h>
int main()
{
	char carr1[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	char carr2[2][3] = {'A', 'B', 'C', 'D', 'E', 'F'};

	printf("%c %c %c %c %c %c\n", carr1[0], carr1[1], carr1[2], carr1[3], carr1[4], carr1[5]);
	printf("%c %c %c %c %c %c\n", carr2[0][0], carr2[0][1], carr2[0][2], carr2[1][0], carr2[1][1], carr2[1][2]);
}

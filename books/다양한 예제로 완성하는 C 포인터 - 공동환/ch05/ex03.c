#include <stdio.h>
int main()
{
	char carr[10] = {'A', 'B', 'C', 'D', '\0'};
	printf("%c%c%c%c%c\n", carr[0], carr[1], carr[2], carr[3], carr[4]);
	printf("%d%d%d%d%d\n", carr[0], carr[1], carr[2], carr[3], carr[4]);
}

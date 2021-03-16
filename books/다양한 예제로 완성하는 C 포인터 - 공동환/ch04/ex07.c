#include <stdio.h>
int main()
{
	char carr[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

	printf("%c %c %c %c %c %c\n", carr[0], carr[1], carr[2], carr[3], carr[4], carr[5]);
	printf("%c %c %c %c %c %c\n", (carr+5)[0], (carr+5)[-1], (carr+5)[-2], (carr+5)[-3], (carr+5)[-4], (carr+5)[-5]);
	printf("%c %c %c %c %c %c\n", (carr+3)[-3], (carr+3)[-2], (carr+3)[-1], (carr+3)[0], (carr+3)[1], (carr+3)[2]);

}

#include <stdio.h>
int main()
{
	char carr[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	char *cp = carr;

	printf("%c %c %c %c %c %c\n", cp[0], cp[1], cp[2], cp[3], cp[4], cp[5]);

	cp = carr+5;
	printf("%c %c %c %c %c %c\n", cp[0], cp[-1], cp[-2], cp[-3], cp[-4], cp[-5]);

	cp = carr+3;
	printf("%c %c %c %c %c %c\n", cp[-3], cp[-2], cp[-1], cp[0], cp[1], cp[2]);
}

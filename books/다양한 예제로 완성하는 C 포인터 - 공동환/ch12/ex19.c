#include <stdio.h>
#include <string.h>
void main()
{
	char c = 'A';
	int n = 100;
	double d = 80000.123;
	char *str = "ABCDEF";

	char temp[100];
	char *p = temp;

	memcpy(p, &c, sizeof(char));
	memcpy(p += sizeof(char), &n, sizeof(int));
	memcpy(p += sizeof(int), &d, sizeof(double));
	memcpy(p += sizeof(double), &str, sizeof(char *));

	printf("%s\n", *(char**)p);
	p -= sizeof(double);
	printf("%.3lf\n", *(double*)p);
	p -= sizeof(int);
	printf("%d\n", *(int *)p);
	p -= sizeof(char);
	printf("%c\n", *p);
}

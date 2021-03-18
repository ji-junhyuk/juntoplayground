#include <stdlib.h>
#include <stdio.h>
struct _sIntData
{
	int n1;
	int n2;
};

struct _sStrData
{
	char str1[20];
	char *str2;
};

int main()
{
	struct _sIntData di, *dip;
	struct _sStrData ds, *dsp;

	dip = &di;
	dsp = &ds;
	ds.str2 = (char *)malloc(sizeof(char)*20);

 	scanf("%d %d\n", &dip->n1, &dip->n2);
	scanf("%s %s\n", dsp->str1, dsp->str2);
	printf("%d %d\n", dip->n1, dip->n2);
	printf("%s %s\n", dsp->str1, dsp->str2);
}

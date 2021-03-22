#include <stdio.h>
struct _sData
{
	char c;
	int n;
};
typedef struct _sData SDATA, *PSDATA;
SDATA data1, data2, *pd1;

void printData(SDATA data)
{
	printf("%c, %d\n", data.c, data.n);
}

void main()
{
	SDATA data3;
	PSDATA pd2;

	pd1 = &data1;
	pd2 = &data2;

	data1.c = 'A'; data1.n = 10;
	data2.c = 'B'; data2.n = 20;
	data3.c = 'C'; data3.n = 30;

	printData(*pd1);
	printData(*pd2);
	printData(data1);
	printData(data2);
	printData(data3);
}

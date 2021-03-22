#include <stdio.h>
typedef struct _sData
{
	char str1[20];
	char str2[20];
} DATA, *PDATA;

void main()
{
	DATA data1 = {"abc", "ABC"}, data2 = {"def", "DEF"};

	printf("%s %s\n", data1.str1, data1.str2);
	printf("%s %s\n", data2.str1, data2.str2);

	fgets(data1.str1, 20, stdin);
	fgets(data1.str2, 20, stdin);
	printf("%s %s\n", data1.str1, data1.str2);
}

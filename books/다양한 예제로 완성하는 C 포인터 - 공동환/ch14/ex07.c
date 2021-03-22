#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _sData
{
	char *str1;
	char *str2;
} DATA, *PDATA;

char *InputStr()
{
	char temp[100] = {0};
	char *str;

	fgets(temp, 100, stdin);
	str = (char *)malloc(strlen(temp)+1);
	strcpy(str, temp);

	return str;
}

void main()
{
	DATA data1 = {"abc", "ABC"}, data2 = {"def", "DEF"};
	printf("%s %s\n", data1.str1, data1.str2);
	printf("%s %s\n", data2.str1, data2.str2);

	data1.str1 = InputStr();
	data1.str2 = InputStr();
	printf("%s %s\n", data1.str1, data1.str2);
}

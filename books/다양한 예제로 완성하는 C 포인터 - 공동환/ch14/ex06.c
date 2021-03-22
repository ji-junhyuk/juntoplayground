#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _sData
{
	char *str1;
	char *str2;
} DATA, *PDATA;

void main()
{
	DATA data1 = {"abc", "ABC"}, data2 = {"def", "DEF"};
	char temp[100];
	printf("%s %s\n", data1.str1, data1.str2);
	printf("%s %s\n", data2.str1, data2.str2);

	memset(temp, 0, sizeof(char)*100);
	fgets(temp, 100, stdin);
	data1.str1 = (char *)malloc(strlen(temp)+1);
	strcpy(data1.str1, temp);

	memset(temp, 0, sizeof(char)*100);
	fgets(temp, 100, stdin);
	data1.str2 = (char *)malloc(strlen(temp)+1);
	strcpy(data1.str2, temp);

	printf("%s %s\n", data1.str1, data1.str2);
}

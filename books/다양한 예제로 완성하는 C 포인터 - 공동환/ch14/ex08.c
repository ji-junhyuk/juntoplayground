#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _sData
{
	char *smallStr;
	char *largeStr;
} DATA, *PDATA;

char AlphaRandSmall()
{
	return rand()%26 + 'a';
}

char AlphaRandLarge()
{
	return rand()%26 + 'A';
}

char *StrRand(int type, int n)
{
	char temp[20] = {0};
	char *str;
	int i;
	
	if (type == 1)
	{
		i = 0;
		while (i < n)
		{
			temp[i] = AlphaRandSmall();
			i++;
		}
	}
	else if (type == 2)
	{
		i = 0;
		while (i < n)
		{
			temp[i] = AlphaRandLarge();
			i++;
		}
	}
	else
		return NULL;

	str = (char *)malloc(strlen(temp)+1);
	strcpy(str, temp);
	return str;
}

void main()
{
	DATA darr[10];
	int i;

	i = 0;
	while (i < 10)
	{
		darr[i].smallStr = StrRand(1, rand()%5 + 6);
		darr[i].largeStr = StrRand(2, rand()%5 + 6);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		printf("%-20s %-20s\n", darr[i].smallStr, darr[i].largeStr);
		printf("%-20s %-20s\n", (darr+i)->smallStr, (darr+i)->largeStr);
		i++;
	}
}


#include <stdio.h>

void swap_str(char *x, char *y)
{
	char *temp;
	while (*x && *y)
	{
		char t = *x; 
		*x++ = *y; 
		*y++ = t;
	}
	
	if (*x)
	{
		temp = x;
		while (*x)
			*y++ = *x++;
		*temp = *y = '\0';
	}
	else if (*y)
	{
		temp = y;
		while (*y) 
			*x++ = *y++;
		*temp = *x = '\0';
	}
	else 
		*x = *y = '\0';
}

int main()
{
	char s1[128], s2[128];

	printf("s1: "); scanf("%s", s1);
	printf("s2: "); scanf("%s", s2);

	swap_str(s1, s2);

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);

	return 0;
}

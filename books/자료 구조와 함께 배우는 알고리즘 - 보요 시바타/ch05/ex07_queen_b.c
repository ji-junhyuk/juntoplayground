#include <stdio.h>

int pos[8];

void print()
{
	int i;

	i = 0;
	while (i < 8)
	{
		printf("%2d", pos[i]);
		i++;
	}
	puts("");
}

void set(int i)
{
	int j;

	j = 0;
	while (j < 8)
	{
		pos[i] = j;
		if (i == 7)
			print();
		else
			set(i+1);
		j++;
	}
}

int main()
{
	set(0);

	return 0;
}

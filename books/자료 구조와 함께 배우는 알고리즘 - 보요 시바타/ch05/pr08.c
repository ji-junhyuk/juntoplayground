#include <stdio.h>
int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];

void print()
{
	int i, j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			printf("%s", j == pos[i] ? "●" : "○");
			j++;
		}
		puts("");
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
		if (!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+7])
		{
			pos[i] = j;
			if (i == 7)
				print();
			else
			{
				flag_a[j] = flag_b[i+j] = flag_c[i-j+7] = 1;
				set(i+1);
				flag_a[j] = flag_b[i+j] = flag_c[i-j+7] = 0;
			}
		}
		j++;
	}
}

int main()
{
	int i;

	for (i = 0; i < 8; i++)
		flag_a[i] = 0;
	for (i = 0; i < 15; i++)
		flag_b[i] = flag_c[i] = 0;

	set(0);

	return 0;
}

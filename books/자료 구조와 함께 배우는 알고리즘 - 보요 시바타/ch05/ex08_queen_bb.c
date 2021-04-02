#include <stdio.h>
int flag[8];
int pos[8];

void print(void)
{
	int i;
	
	i = 0;
	while (i < 3)
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
	while (j < 3)
	{
		printf("@@@\n");
		if (!flag[j])
		{
			printf("AAA\n");
			pos[i] = j;
			if (i == 2)
				print();
			else
			{
				printf("BBB\n");
				flag[j] = 1;
				set(i+1);
				flag[j] = 0;
			}
		}
		j++;
		printf("j++\n");
	}
}

int main(void)
{
	int i = 0;

	i = 0;
	while (i < 3)
	{
		flag[i] = 0;
		i++;
	}
	set(0);

	return 0;
}


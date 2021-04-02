#include <stdio.h>
#include "../ch04/ex01_IntStack.h"

int flag_a[4];
int flag_b[7];
int flag_c[7];
int pos[4];

void print()
{
	int i;

	i = 0;
	while (i < 4)
	{
		printf("%2d", pos[i]);
		i++;
	}
	puts("");
}

void set(int i)
{
	int j;
	IntStack jstk;
	Initialize(&jstk, 8);

Start:
	while (1)
	{
		j = 0;
		while (1)
		{
			while (j < 4)
			{
				if (!flag_a[j] && !flag_b[i+j] && !flag_c[i-j+3])
				{
					pos[i] = j;
					if (i == 3)
					{
						print();
					}
					else
					{
						flag_a[j] = flag_b[i+j] = flag_c[i-j+3] = 1;
						i++;
						Push(&jstk, j);
						goto Start;
					}
				}
				j++;
			}
			if (--i == -1) return;
			Pop(&jstk, &j);
			flag_a[j] = flag_b[i+j] = flag_c[i-j+3] = 0;
			j++;
		}
	}
	Terminate(&jstk);
}

int main()
{
	int i;

	for (i = 0; i < 4; i++)
		flag_a[i] = 0;
	for (i = 0; i < 7; i++)
		flag_b[i] = flag_c[i] = 0;

	set(0);

	return 0;
}

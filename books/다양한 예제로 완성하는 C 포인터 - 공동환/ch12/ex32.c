#include <stdio.h>
void Sort(int list[], int size, int (*pred)(int, int))
{
	int i, j, min;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i+1;
		while (j < size)
		{
			if (pred(list[j], list[min]))
				min = j;
			j++;
		}
		{
			int temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
		i++;
	}
}

int Less(int a, int b)
{
	return a < b;
}

int Greater(int a, int b)
{
	return a > b;
}

void main()
{
	int list[5] = {5, 2, 9, 3, 1};

	printf("%d %d %d %d %d\n", list[0], list[1], list[2], list[3], list[4]);
	Sort(list, 5, Less);
	printf("%d %d %d %d %d\n", list[0], list[1], list[2], list[3], list[4]);
	Sort(list, 5, Greater);
	printf("%d %d %d %d %d\n", list[0], list[1], list[2], list[3], list[4]);
}

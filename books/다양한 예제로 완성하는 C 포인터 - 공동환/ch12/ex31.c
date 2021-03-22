#include <stdio.h>
void Sort(int list[], int size)
{
	int i, j, min;
	
	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i+1;
		while (j < size)
		{
			if (list[j] < list[min])
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

void main()
{
	int list[5] = {50, 20, 90, 10, 30};

	printf("%d %d %d %d %d\n", list[0], list[1], list[2], list[3], list[4]);
	Sort(list, 5);
	printf("%d %d %d %d %d\n", list[0], list[1], list[2], list[3], list[4]);
}

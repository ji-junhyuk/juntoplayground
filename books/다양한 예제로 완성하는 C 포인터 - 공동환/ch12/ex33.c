#include <stdio.h>
#include <stdlib.h>

void Sort(void * list[], int size, int (*pred)(void *, void *))
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
			void *temp = list[i];
			list[i] = list[min];
			list[min] = temp;
		}
		i++;
	}
}

int LessInt(void *a, void *b)
{
	return *(int *)a < *(int *)b;
}

int Greater(void *a, void *b)
{
	return *(double *)a > *(double *)b;
}

void main()
{
	void *listInt[5] = {0};
	void *listDbl[5] = {0};
	int i;

	listInt[0] = malloc(sizeof(int)); *(int *)listInt[0] = 50;
	listInt[1] = malloc(sizeof(int)); *(int *)listInt[1] = 20;
	listInt[2] = malloc(sizeof(int)); *(int *)listInt[2] = 90;
	listInt[3] = malloc(sizeof(int)); *(int *)listInt[3] = 10;
	listInt[4] = malloc(sizeof(int)); *(int *)listInt[4] = 30;

	printf("%d %d %d %d %d\n", *(int *)listInt[0], *(int *)listInt[1], *(int *)listInt[2], *(int *)listInt[3], *(int *)listInt[4]);
	Sort(listInt, 5, LessInt);
	printf("%d %d %d %d %d\n", *(int *)listInt[0], *(int *)listInt[1], *(int *)listInt[2], *(int *)listInt[3], *(int *)listInt[4]);

	i = 0;
	while (i < 5)
	{
		free(listInt[i]);
		i++;
	}
	listDbl[0] = malloc(sizeof(double)); *(double *)listDbl[0] = 50.5;
	listDbl[1] = malloc(sizeof(double)); *(double *)listDbl[1] = 20.5;
	listDbl[2] = malloc(sizeof(double)); *(double *)listDbl[2] = 90.5;
	listDbl[3] = malloc(sizeof(double)); *(double *)listDbl[3] = 10.5;
	listDbl[4] = malloc(sizeof(double)); *(double *)listDbl[4] = 30.5;

	printf("%g %g %g %g %g\n", *(double *)listDbl[0], *(double *)listDbl[1], *(double *)listDbl[2], *(double *)listDbl[3], *(double *)listDbl[4]);
	Sort(listDbl, 5, Greater);
	printf("%g %g %g %g %g\n", *(double *)listDbl[0], *(double *)listDbl[1], *(double *)listDbl[2], *(double *)listDbl[3], *(double *)listDbl[4]);
}

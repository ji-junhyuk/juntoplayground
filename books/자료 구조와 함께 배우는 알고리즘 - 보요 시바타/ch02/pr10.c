#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
void shuffle(int a[], int n)
{
	int i, j;

	srand(time(NULL));
	i = 0;
	while (i < n)
	{
		j = rand() % n;
		if (i != j)
			swap(int, a[i], a[j]);
		i++;
	}
}

int main()
{
	int i;
	int a[] = {1,2,3,4,5};

	shuffle(a, 3);

	i = 0;
	while (i < 5)
	{
		printf("a[%d] = %d\n", i, a[i]);
		i++;
	}
	return 0;
}	

#include <stdio.h>
int search_idx(const int a[], int n, int key, int idx[])
{
	int i, j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (a[i] == key)
			idx[j++] = i;
		i++;
	}
	idx[j] = '\0';

	j = 0;
	while (idx[j])
	{
		j++;
	}
	return j;
}

int main()
{
	int i;
	int a[] = {1,9,2,9,4,6,7,9};
	int b[500];
	search_idx(a, 8, 9, b);

	i = 0;
	while (b[i])
	{
		printf("b[%d]: %d\n", i, b[i]);
		i++;
	}

	printf("search_idx: %d\n", search_idx(a, 8, 9, b));

	return 0;
}

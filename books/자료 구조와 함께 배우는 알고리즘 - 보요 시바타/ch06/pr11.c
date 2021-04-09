#include <stdio.h>
#include <stdlib.h>

void bin_insertion(int a[], int n)
{
	int i, j;

	for (i = 1; i < n; i++)
	{
		int key = a[i];
		int pl = 0;
		int pr = i - 1;
		int pc;
		int pd;
		do {
			pc = (pl + pr) / 2;
			if (a[pc] == key)
				break;
			else if (a[pc] < key)
				pl = pc + 1;
			else
				pr = pc - 1;
		} while (pl <= pr);

		pd = (pl <= pr) ? pc + 1 : pr + 1;

		memmove(&a[pd+1], &a[pd], (i - pd) * sizeof(int));
		/*
		  첫번째 인자 : 복사 한 걸 붙여 넣을 메모리
		  두번째 인자 : 복사할 메모리
		  세번째 인자 : 복사할 바이트 길이
		  반환형 : 첫번째 인자를 반환
memcpy: 복사해서 붙여넣기 (더 빠름)
memmove: 복사할 것을 버퍼에 붙여넣고 해당 위치에 가서 버퍼에 복사된 것을 붙여넣는 식 (안정성 높음)
		*/
		a[pd] = key;
	}
}

int main()
{
	int i, nx;
	int *x;

	printf("nx: ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	i = 0;
	while (i < nx)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
		i++;
	}

	bin_insertion(x, nx);

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}

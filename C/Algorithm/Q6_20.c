//
// Created by junto on 20. 12. 27..
//

#include <stdio.h>
#include <stdlib.h>
//#include <stdio.h>
//#include <stdlib.h>

/*--- x, y가 가리키는 n 바이트의 메모리 영역을 교환 ---*/
static void memswap(void *x, void *y, size_t n)
{
	unsigned char *a = (unsigned char *)x;
	unsigned char *b = (unsigned char *)y;

	for (; n--; a++, b++) {
		unsigned char c = *a;
		*a = *b;
		*b = c;
	}
}

void q_sort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	if (nmemb > 0) {
		size_t pl = 0;					/* 왼쪽 커서 */
		size_t pr = nmemb - 1;			/* 오른쪽 커서 */
		size_t pv = nmemb;				/* 피벗 */
		size_t pt = (pl + pr) / 2;		/* 피벗 업데이트 */
		char *v = (char *)base;			/* 첫 번째 요소에 대한 포인터 */
		char *x;						/* 피벗에 대한 포인터 */

		do {
			if (pv != pt) x = &v[(pv = pt) * size];
			while (compar((const void *)&v[pl * size], x) < 0) pl++;
			while (compar((const void *)&v[pr * size], x) > 0) pr--;
			if (pl <= pr) {
				pt = (pl == pv) ? pr : (pr == pv) ? pl : pv;
				memswap(&v[pl * size], &v[pr * size], size);
				pl++;
				if (pr == 0)	/* 부호가 없는 정수 0부터 1씩 감소를 피합니다. */
					goto QuickRight;
				pr--;
			}
		} while (pl <= pr);

		if (0 < pr)      q_sort(&v[0], pr + 1, size, compar);
	QuickRight:
		if (pl < nmemb - 1) q_sort(&v[pl * size], nmemb - pl, size, compar);
	}
}

int int_cmp(const int *a, const int *b)
{
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main(void)
{
    int i, nx;
    int *x;

    printf("q_sort function sort\n");
    printf("number of element:");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    q_sort(x,
           nx,
           sizeof(int),
           (int(*)(const void *, const void *))int_cmp
    );

    puts("Ascending order.");
    for (i = 0; i < nx; i++)
        printf("x[%d] = %d \n", i, x[i]);

    free(x);

    return 0;
}

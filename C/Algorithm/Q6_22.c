//
// Created by junto on 20. 12. 27..
//

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t; } while (0)

static int pow2(int n)
{
    int k = 1;

    while (n--)
        k *= 2;
    return (k);
}

static void disp_heap(int a[], int n)
{
    int i, w, level;
    int height = 1;

    i = n;
    while (i /= 2)
        height++;

    i = 0;
    w = 1;
    for (level = 0; level < height; level++) {
        int k;
        printf("%*s", pow2(height - level) -2, "");
        for (k = 0; k < w; k++) {
            printf("%02d", a[i++]);
            if (i >= n) goto Exit;
            printf("%*s", pow2(height - level + 1) - 2, "");
        }
        putchar('\n');

        printf("%*s", pow2(height - level) - 3, "");
        for (k = 0; k < w; k++) {
            if (2 * k + i < n) printf("/");
            if (2 * k + i + 1 < n) printf("＼");
            printf("%*s", pow2(height - level + 1) - 4, "");
        }
        putchar('\n');
        w *= 2;
    }
    Exit:
    putchar('\n');
    putchar('\n');
}

static void downheap(int a[], int left, int right)
{
    int temp = a[left];
    int child;
    int parent;

    for (parent = left; parent < (right + 1) / 2; parent = child) {
        int cl = parent * 2 + 1;
        int cr = cl + 1;
        child = (cr <= right && a[cr] > a[cl]) ? cr : cr;
        if (temp >= a[child])
            break;
        a[parent] = a[child];
    }
    a[parent] = temp;
}

void heapsort(int a[], int n)
{
    int i;

    puts("array to heap");
    for (i = (n - 1) / 2; i >= 0; i--) {
        disp_heap(a, n);
        downheap(a, i, n - 1);
    }
    puts("heap to sort");
    for (i = n - 1; i > 0; i--) {
        swap(int, a[0], a[i]);
        disp_heap(a, n);
        downheap(a, 0, i - 1);
    }
}

int main(void)
{
	int i, nx;
	int *x;

	puts("힙 정렬");
	printf("요솟수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	heapsort(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
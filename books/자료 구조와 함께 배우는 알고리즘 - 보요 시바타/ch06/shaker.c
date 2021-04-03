#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

/*--- 양방향 버블 정렬(셰이커 정렬) ---*/
void shaker(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	int last = right;
	int m = 0;

	while (left < right) {
		int j;
		for (j = right; j > left; j--) {
			printf("첫번쟤 for문\n");
			if (a[j - 1] > a[j]) {
				printf("첫번쨰 for문의 if문, last값:%d\n", last);
					printf("%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		}
		left = last;

		for (j = left; j < right; j++) {
			printf("두번쨰 for문\n");
			if (a[j] > a[j + 1]) {
					printf("%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
				printf("첫번쨰 for문의 if문, last값:%d\n0", last);
				swap(int, a[j], a[j + 1]);
				last = j;
			}
		}
		printf("아니 여기서 right와 left값 둘다 1 아닌가? %d %d\n", left, last);
		right = last;
	}
}

int main(void)
{
	int i, nx;
	nx = 8;
	int x[] = {9,1,3,4,5,6,7,8};		

	shaker(x, nx);					

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);


	return 0;
}

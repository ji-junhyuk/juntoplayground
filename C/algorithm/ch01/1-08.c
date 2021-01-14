//
// Created by junto on 21. 1. 14..
//
#include <stdio.h>

int main(void)
{
	int i, n;
	int sum;

	scanf("%d", &n);

	sum = (n + 1) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0);
//    sum = (n + 1) * n / 2;

	printf("Sum to %d: %d", n, sum);

	return 0;
}
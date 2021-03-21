#include <stdio.h>
void main()
{
	printf("& : %d\n", 0 & 1);
	printf("& : %d\n", 1 & 1);
	printf("& : %d\n", 2 & 3);
	printf("& : %d\n", 5 & 7);
	printf("========\n");
	printf("| : %d\n", 0 | 1);
	printf("| : %d\n", 1 | 1);
	printf("| : %d\n", 2 | 3);
	printf("| : %d\n", 5 | 7);
	printf("========\n");
	printf("^ : %d\n", 0 ^ 1);
	printf("^ : %d\n", 1 ^ 1);
	printf("^ : %d\n", 2 ^ 3);
	printf("^ : %d\n", 5 ^ 7);
	// 비트연산자 ^는 비트 1의 개수가 홀수이면 1이고, 짝수이면 0인 특징이 있다.
	printf("========\n");
	printf("~ : %d\n", ~0);
	printf("~ : %d\n", ~1);
	printf("~ : %d\n", ~2);
	printf("~ : %d\n", ~-2);
}

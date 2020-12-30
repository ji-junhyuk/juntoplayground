//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>

#define swap(type, x, y)  do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	char *s1 = "ABCD";
	char *s2 = "EFGH";

	printf("포인터 s1은 \"%s\"을 가리킵니다.\n", s1);
	printf("포인터 s2는 \"%s\"을 가리킵니다.\n", s2);

	swap(char*, s1, s2);

	printf("포인터 s1은 \"%s\"을 가리킵니다.\n", s1);
	printf("포인터 s2는 \"%s\"을 가리킵니다.\n", s2);

	return 0;
}

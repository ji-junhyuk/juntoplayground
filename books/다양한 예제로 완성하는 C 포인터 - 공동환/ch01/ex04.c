#include <stdio.h>
int main()
{
	char c = 'A';

	printf("%d\n", c);
	printf("%x %p\n", c, &c);
}
/*
65
41 0x7ffd5285e9e7(계속 값 바뀜)
책에서 나온 printf("%d", &c)는 컴파일에러(변수타입 불일치 int - char*)
*/

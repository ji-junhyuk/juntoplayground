#include <stdio.h>
union _data
{
	char carr[4];
	int n;
};

int main()
{
	union _data u;
	u.n = 0x65666768;

	printf("%p %d\n", &u.n, u.n);
	printf("%c %c %c %c\n", u.carr[0], u.carr[1], u.carr[2], u.carr[3]);
}

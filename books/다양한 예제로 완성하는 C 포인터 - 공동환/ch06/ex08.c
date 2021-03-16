#include <stdio.h>
struct _sData
{
	int n1;
	int n2;
};

union _uData
{
	int n1;
	int n2;
};

int main()
{
	struct _sData s1 = {10, 20};
	union _uData u1 = {10};

	printf("%ld %ld\n", sizeof(s1), sizeof(u1));
	printf("%d %d\n", s1.n1, s1.n2);
	printf("%d %d\n", u1.n1, u1.n2);
}

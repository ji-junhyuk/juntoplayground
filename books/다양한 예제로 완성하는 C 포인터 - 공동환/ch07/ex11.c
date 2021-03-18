#include <stdio.h>
struct _pData
{
	int *ip;
	int **ipp;
};

int main()
{
	int n = 10;
	struct _pData s1;

	s1.ip = &n;
	s1.ipp = &s1.ip;

	printf("%d %d\n", *s1.ip, **s1.ipp);
	printf("%p %p\n", s1.ip, *s1.ipp);
	printf("%p %p\n", &s1.ip, s1.ipp);
	printf("%p %p %p %p %p %p\n",*s1.ipp, s1.ip, &s1, &s1.ip,s1.ipp, &s1.ipp);
}

#include <stdio.h>
int main()
{
	char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E';
	char *ap = &a, *bp = &b, *cp = &c, *dp = &d, *ep = &e;

	printf("%p %p %p %p %p\n", &a, &b, &c, &d, &e);
	printf("%p %p %p %p %p\n", ap, bp, cp, dp, ep);

	printf("%c %c %c %c %c\n", a, b, c ,d ,e);
	printf("%c %c %c %c %c\n", *ap, *bp, *cp, *dp, *ep);
}

#include <stdio.h>
void main()
{
	int n = 20;
	double d = 5.5;
	char *str = "ABCD";
	void *vp;

	vp = &n;
	printf("%d\n", *(int *)vp);

	vp = &d;
	printf("%g\n", *(double *)vp);

	vp = str;
	printf("%s\n", (char *)vp);
}

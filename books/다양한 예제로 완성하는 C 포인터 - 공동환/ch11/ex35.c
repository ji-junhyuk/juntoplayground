#include <stdio.h>
void main()
{
	printf("&& : %d\n", 0 && 1);
	printf("&& : %d\n", 1 && 1);
	printf("&& : %d\n", 10 && 20);
	printf("&& : %d\n", 100 && 200);
	printf("=======\n");
	printf("|| : %d\n", 0 || 1);
	printf("|| : %d\n", 1 || 0);
	printf("|| : %d\n", 1 || 1);
	printf("|| : %d\n", 10 || 100);
	printf("=======\n");
	printf("! : %d\n", !0);
	printf("! : %d\n", !1);
	printf("! : %d\n", !100);
	printf("! : %d\n", !-100);
}

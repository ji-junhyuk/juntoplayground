#include <stdio.h>
struct _string
{
	char *str1;
	char str2[8];
};

int main()
{
	struct _string s1 = {"ABC", "ABC"};

	printf("%s %s\n", s1.str1, s1.str2);
	printf("%ld %ld %ld\n", sizeof(s1), sizeof(s1.str1), sizeof(s1.str2));
}

#include <stdio.h>
int main()
{
	int carr1[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int carr2[2][3] = {'A', 'B', 'C', 'D', 'E', 'F'};

	printf("%ld %ld\n", sizeof(carr1), sizeof(carr2));
	printf("%ld %ld\n", sizeof(carr2[0]), sizeof(carr2[1]));
}

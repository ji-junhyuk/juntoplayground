#include <stdio.h>
int main()
{
	int arr[2][3] = {{10, 20, 30}, {40, 50, 60}};

	printf("%ld %ld %ld\n", sizeof(arr), sizeof(arr[0]), sizeof(arr[1]));
	printf("%ld %ld %ld\n", sizeof(arr[0][0]), sizeof(arr[1][0]), sizeof(arr[0][0]));
}

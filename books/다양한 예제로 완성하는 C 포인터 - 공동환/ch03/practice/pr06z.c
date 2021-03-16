#include <stdio.h>
int main()
{
	int arr[2][3] = {{1,2,3}, {4,5,6}};
	printf("%d %d %d\n", arr[0][0], *arr[0], **arr);
	printf("%d %d %d\n", arr[0][1], *arr[0]+1, *(*arr+1));
	printf("%d %d %d\n", arr[1][0], *arr[1], **(arr+1));
	printf("%d %d %d\n", arr[1][1], *(arr[1]+1), *(*(arr+1)+1));
}

#include <stdio.h>
struct _point
{
	int x;
	int y;
};
int main()
{
	struct _point arr[5] = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}};

	printf("%ld\n", sizeof(struct _point));
	printf("%p %p %p\n", arr, &arr[0].x, &arr[0].y);
	printf("%p %p %p\n", arr+1, &arr[1].x, &arr[1].y);
	printf("%p %p %p\n", arr+2, &arr[2].x, &arr[2].y);
	printf("%p %p %p\n", arr+3, &arr[3].x, &arr[3].y);
	printf("%p %p %p\n", arr+4, &arr[4].x, &arr[4].y);
}

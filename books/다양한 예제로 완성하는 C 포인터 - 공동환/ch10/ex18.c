#include <stdio.h>
void main()
{
	int n = 10;
	int *const np = &n; //포인터 변수에 저장된 주소를 변경하지 못하게 하는 const
	int m = 100;

	n = 20;
	*np = 30;
	//np = &m; 불가능 
	printf("%d %d\n", n, *np);
}

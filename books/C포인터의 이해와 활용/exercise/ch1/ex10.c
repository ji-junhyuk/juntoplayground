#include <stdio.h>

void main()
{
	int num = 5;
	const int limit = 500;
	int *pi;
	const int *pci;

	pi = &num;
	pci = &limit;
	
	printf("num %p %d\n", &num, num);
	printf("limit %p %d\n", &limit, limit);
	printf("pi %p %d\n", &pi, *pi);
	printf("pci %p %d\n", &pci, *pci);

	pci = &num; // 상수 정수 포인터를 역참조하여 값을 읽을 수는 있다.
	//하지만 값을 수정하기 위해 pci포인터를 역참조할 수 는 없다.
//	*pci = 200;
}

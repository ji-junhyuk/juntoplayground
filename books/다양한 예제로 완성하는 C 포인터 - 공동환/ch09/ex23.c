#include <stdio.h>
int function1()
{
	puts("함수1");
	return 1;
}

int function2()
{
	puts("함수2");
	return 2;
}

void main()
{
	int (*func[2])();

	func[0] = function1;
	printf("%d\n", func[0]());

	func[1] = function2;
	printf("%d\n", func[1]());
}

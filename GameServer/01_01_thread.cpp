#include <iostream>
using namespace std;

void func1(void);
void func2(void);
void func3(void);

void func1()
{
	func2();
}

void func2()
{
	func3();
}

void func3()
{
	int a = 0;
}
int main()
{
	func1();
}

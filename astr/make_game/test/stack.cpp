#include <iostream>
#include "stack.h"
using namespace std;

int main(void)
{
	CStack<int> stack_int;
	for (int idx = 0; idx < 100; ++idx)
		stack_int.push(idx + 1);
	while (!stack_int.empty())
		cout << stack_int.pop() << '\n';
	return 0;
}

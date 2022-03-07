#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
	CQueue<int> queue;

	for (int idx = 0; idx < 100; ++idx)
		queue.push(idx + 1);
	while (!queue.empty())
		cout << queue.pop() << '\n';

	cout << "==========\n";
	CCircleQueue<int, 10> queue1;
	for (int idx = 0; idx < 10; ++idx)
		queue1.push(idx + 1);
	for (int idx = 0; idx < 3; ++idx)
		cout << queue1.pop() << '\n';
	cout << "==========\n";
	for (int idx = 0; idx < 4; ++idx)
		queue1.push(idx + 1);
	while (!queue1.empty())
		cout << queue1.pop() << '\n';
}

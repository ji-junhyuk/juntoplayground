#include <iostream>
#include "linked_list.h"

using namespace std;

int main(void)
{
	CLinkedList<int> list_int;
	CLinkedList<float> list_float;

	for (int idx = 0; idx < 100; ++idx)
		list_int.push_back(idx + 1);
	CLinkedList<int>::iterator iter;
	for (iter = list_int.begin(); iter != list_int.end(); ++iter)
	{
		cout << *iter << '\n';
	}
	return (0);
}

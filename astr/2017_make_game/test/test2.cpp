#include <iostream>
#include "linked_list.h"

using namespace std;

int main(void)
{
	CLinkedList<int> list_int;

	for (int idx = 0; idx < 100; ++idx)
		list_int.push_back(idx + 1);

	cout << list_int.size() << '\n';

	CLinkedList<int>::iterator iter;

	for (iter = list_int.begin(); iter != list_int.end(); ++iter)
		cout << *iter << '\n';
	cout << "=========================" << '\n';
	CLinkedList<int>::reverse_iterator riter;
	for (riter = list_int.rbegin(); riter != list_int.rend(); ++riter)
		cout << *riter << '\n';
	return (0);
}

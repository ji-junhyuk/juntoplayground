#include <iostream>
#include "vector.h"

using namespace std;

int main(void)
{
	CVector<int> vec_int;
	for (int idx = 0; idx < 100; ++idx)
		vec_int.push_back(idx + 1);
	return (0);
}

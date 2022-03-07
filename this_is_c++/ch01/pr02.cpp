#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//auto 예약어는 초기값의 형식에 맞춰 선언하는 인스턴스의 형식이 자동으로 결정된다.
	int i_score[5];
	int	sum;

	sum = 0;
	for (int idx = 0; idx < 5; ++idx)
		i_score[idx] = 10;
	for (auto n : i_score)
		sum += n;
	cout << sum << '\n';
	return (0);
}

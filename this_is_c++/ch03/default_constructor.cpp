#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CTest
{
	public:
	//	CTest(void);
	//	CTest(void) = default;
		CTest(void) = delete; //삭제된 함수를 참조하려고 합니다.
		int m_i_data = 5;
};

//CTest::CTest(void) { }

int _tmain(int argc, _TCHAR *argv[])
{
	CTest a;
	cout << a.m_i_data << '\n';
	return 0;
}

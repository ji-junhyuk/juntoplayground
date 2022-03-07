#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CTest
{
	int m_i_data;
	public:
	CTest()
	{
		cout << "CTest::CTest()" << '\n';
	}
	~CTest()
	{
		cout << "~CTest::CTest())" << '\n';
	}
};

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "begin" << '\n';
//	CTest *p_data = new CTest;
	CTest *p_data = new CTest[3];
	cout << "Test" << '\n';
	delete[] p_data;
	cout << "end" << '\n';
	/*
	 * begin -> CT() ->~CT() -> end
	 * 만일 동적으로 생성하지 않고 지역 변수로 선언했다면 ENd가 출력된 후 소멸자가 호출됐을 것이다.
	 */
}

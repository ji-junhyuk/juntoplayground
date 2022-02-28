#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CTest
{
	public:
		CTest()
		{
			cout << "CTest() 생성자 함수" << '\n';
			m_i_data = 50;
		}
		int m_i_data;
		void print_data(void);
};

void CTest::print_data(void)
{
	cout << m_i_data << '\n';
	/*
	 * 모든 멤버 변수는 기본적으로 지역 변수->멤버 변수->전역 변수 순으로 식별자를 검색한다.
	 */
}

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "_tmain() 함수 시작" << '\n';
	CTest t;
	t.print_data();
	cout << "_tmain() 함수 끝" << '\n';
	return (0);
}

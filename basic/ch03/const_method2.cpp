#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CTest
{
	public:
		CTest(int i_param) : m_i_data(i_param) { };
		~CTest() { }
		int get_data() const
		{
			// 상수형 메서드라도 mutable 멤버 변수에는 값을 쓸 수 있다.
			m_i_data = 20;
			return m_i_data;
		}
		int set_data(int i_param) { m_i_data = i_param; }
	private:
		mutable int m_i_data = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CTest a(10);
	cout << a.get_data() << '\n';
}

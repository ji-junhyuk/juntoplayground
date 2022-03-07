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
		//	m_i_data = 20; // m_i_data'은(는) const 개체를 통해 액세스되고 있으므로 수정할 수 없습니다.
		//	set_data(20); // 'this' 포인터를 'const CTest'에서 'CTest &'(으)로 변환할 수 없습니다. 여기서 알 수 있는 것은 const는 this 포인터를 상수형 포인터로 변경하는 것이다.
			return m_i_data;
		}
		int set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CTest a(10);
	cout << a.get_data() << '\n';
}

#include "../ch01/stdafx.h"

class CTest
{
	public:
		CTest(int i_param) : m_i_data(i_param) { m_i_count++; }
		int get_data() { return m_i_data; };
		void reset_count () { m_i_count = 0; };
		static int get_count()
		{
			return m_i_count;
		};
	private:
		int m_i_data;
		static int m_i_count; // 정적 멤버 변수 선언(정의아님)
};

int CTest::m_i_count = 0; // CTest 클래스 멤버 변수 정의

int _tmain(int argc, _TCHAR *argv[])
{
	CTest a(5), b(10);

	cout << a.get_count() << '\n';
	b.reset_count();
	cout << CTest::get_count() << '\n'; // 정적 멤버에 인스턴스 없이도 접근이 가능하다
}

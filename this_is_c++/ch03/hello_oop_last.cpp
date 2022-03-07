#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CUserData
{
	public:
		int m_i_age;
		char m_c_name[32];
		void print(void)
		{
			cout << m_i_age << ' ' << m_c_name << '\n';
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CUserData user = {10, "junto"};
	user.print();
	return (0);
}
/*
 * m_i_age와 m_c_name이 print 함수 내부에 선언된 지역변수가 아니라 print()함수가 속한 클래스의 멤버 변수이다.
 *
 * 19번째 줄, 근본적인 문제는 '멤버 변수 초기화라는 중요한 일을 사용자가 알아서 하도록 방치했다'는 것이다.
 * 물론 C++ '생성자'라는 매우 독특한 함수로 이 문제를 해결했다.
 */

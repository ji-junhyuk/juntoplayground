
#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CMyData
{
	public:
		CMyData(int i_param) : m_i_data(i_param) { };
		void print_data()
		{
			//m_i_data의 값을 출력한다.
			cout << m_i_data << '\n';
			// CMyData 클래스의 멤버인 m_i_data 값을 출력
			cout << CMyData::m_i_data << '\n';
			// 메서드를 호출한 인스턴스의 m_i_data 값을 출력
			cout << this->m_i_data << '\n';
			// 메서드를 호출한 인스턴스의 CMyData 클래스 멤버 m_i_data를 출력한다.
			cout << this->CMyData::m_i_data << '\n';
		}
	private:
		int m_i_data;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a(5), b(10);
	a.print_data(); //&a, &b는 보이지 않지만 실제로는 전달된다.
	b.print_data();
	return (0);
}

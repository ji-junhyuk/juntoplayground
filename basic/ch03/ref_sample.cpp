#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CRefTest
{
	public:
		CRefTest(int &i_param) : m_i_data(i_param) { };
//		CRefTest(int &i_param) { m_i_data = i_param; } //-> =는 단순대입연산자이다. 따라서 선언 및 정의가 아니고 이미 선언된 인스턴스를 이용해서 연산하는 것에 불과하다. 참조를 초기화해야 합니다 라는 오류가 발생.
//		CRefTest(int i_param) : m_i_data(i_param) { }; // 생성자의 매개변수를 참조하는 형식이 아니다. 함수의 매개변수는 함수 내부의 자동변수와 같으므로 함수가 반환될 때 매개변수는 소멸한다. 사라질 대상에 대한 참조자가 초기화되는 결과를 초래한다. 참조자의 내부를 뜯어보면 포인터와 똑같다. 다만 가리키는 대상을 반드시 규정하고, 중간에 원본 대상을 바꿀수 없다는 정도가 다르다.
		int get_data(void) { return m_i_data; }
		// 참조형 멤버는 객체가 생성될 때 반드시 초기화해야 한다.
	private:
		int &m_i_data;
};

int _tmain(int argc, _TCHAR *argv[])
{
	int a = 10;
	CRefTest t(a);
	cout << t.get_data() << '\n';
	a = 20;
	cout << t.get_data() << '\n';
}

#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData() { cout << "CMyData()" << '\n'; }
		int get_data(void) const { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a;
	a.set_data(10);
	CMyData b(a);
	cout << b.get_data() << '\n';
}
// 포인터를 사용하는 복사 생성자의 선언과 정의가 없으므로 함수 형태로 호출된 복사 생성자는 아무런 문제 없이 실행되어 10이라는 결과값을 출력

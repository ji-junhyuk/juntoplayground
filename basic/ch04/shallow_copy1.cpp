#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData(int i_param)
		{
			m_p_i_data = new int;
			*m_p_i_data = i_param;
		}
		CMyData(const CMyData &rhs)
		{
			cout << "CMyData(const CMyData &):" << '\n';
			m_p_i_data = new int;
			*m_p_i_data = *rhs.m_p_i_data; // 포인터가 가리키는 위치에 값을 복사한다.
		}
		~CMyData()
		{
			delete m_p_i_data;
			// 해제된 메모리 한번 더 해제
		}
		int get_data()
		{
			if (m_p_i_data != NULL)
				return *m_p_i_data;
			return (0);
		}
	private:
		int *m_p_i_data = nullptr;
};

int _tmain(int argc, _TCHAR *argv[])
{
//	CMyData a(10);
//	CMyData b(a); // 깊은 복사를 수행할 별도의 복사 생성자가 없기 때문에 컴파일러가 만들어 넣은 복사 생성자가 작동한다.
// 새로 메모리를 할당하고 단순히 포인터 변수의 주소를 같은 값으로 만드는 것이 아닌, 포인터가 가리키는 대상 메모리에 저장된 값을 가져와 다시 포인터가 가리키는 대상 메모리로 복사한 것
	CMyData a(10);
	CMyData b(20);

	a = b;
	cout << a.get_data() << '\n';
	// 단순 대입을 시도하면 기본적으로 얕은 복사가 수행되므로 발생하는 문제이다.

}

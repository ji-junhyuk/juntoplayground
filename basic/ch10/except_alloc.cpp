#include "../ch01/stdafx.h"

class CTest
{
	public:
		CTest(int i_size)
		{
			m_p_size_data = new char[i_size];
		}
		~CTest()
		{
			delete[] m_p_size_data;
			cout << "정상적으로 객체가 소멸함" << '\n';
		}
	private:
		char *m_p_size_data;
};

int _tmain(int argc, _TCHAR *argv[])
{
	try
	{
		int i_size;
		cout << "input size: ";
		cin >> i_size;
		CTest a(i_size);
	}
	catch (bad_alloc &exp)
	{
		cout << exp.what() << '\n';
		cout << "Error: CTest()" << '\n';
	}
	return 0;
}

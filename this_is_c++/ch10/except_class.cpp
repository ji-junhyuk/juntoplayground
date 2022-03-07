#include "../ch01/stdafx.h"

using namespace std;

class CMyException 
{
public:
	CMyException(int i_code, const char* p_size_msg) 
	{
		m_i_error_code = i_code; 
		strcpy_s(m_size_msg, sizeof(m_size_msg), p_size_msg);
	}

	int get_error_code() const
	{
		return m_i_error_code;
	}

	const char* get_msg() const
	{
		return m_size_msg; 
	}

private:
	int m_i_error_code;
	char m_size_msg[128];
};

int main()
{
	try
	{
		int input = 0;
		cout << "양의 정수를 입력하세요: ";
		cin >> input; 
		if (input < 0)
		{
			CMyException except(10, "양의 정수를 입력해야 합니다"); 
			throw except; 
		}
	}
	catch (CMyException& exception)
	{
		cout << "ERROR CODE [" << exception.get_error_code() << "] " << exception.get_msg() << endl;
	}
	return 0;
}

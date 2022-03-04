#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData() { m_p_size_data = new char[32]; }
		virtual ~CMyData()
		{
			cout << "~CMyData()" << '\n';
			delete m_p_size_data;
		}
	private:
		char *m_p_size_data;
};

class CMyDataEx : public CMyData
{
	public:
		CMyDataEx() { m_p_i_data = new int; }
		~CMyDataEx()
		{
			cout << "~CMyDataEx())" << '\n';
			delete m_p_i_data;
		}
	private:
		int *m_p_i_data;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData *p_data = new CMyDataEx;
	delete p_data;
}

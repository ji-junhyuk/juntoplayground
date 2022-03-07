#include "../ch01/stdafx.h"

class CMyInterface
{
	public:
		CMyInterface()
		{
			cout << "CMyInterface()" << '\n';
		}
		virtual int get_data() const = 0;
		virtual void set_data(int i_param) = 0;
};

class CMyData : public CMyInterface
{
	public:
		CMyData() { cout << "CMyData()" << '\n'; }
		virtual int get_data() const { return m_i_data; }
		virtual void set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData a;
	a.set_data(5);
	cout << a.get_data() << '\n';
	return 0;
}

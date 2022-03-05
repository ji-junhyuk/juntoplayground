#include "../ch01/stdafx.h"

template<typename T>
class CMyData
{
	public:
		CMyData(T param) : m_data(param) { }
		T get_data() const { return m_data; }
		operator T() { return m_data; }
		void set_data(T param) { m_data = param; }
	private:
		T m_data;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData<int> a(5);
	cout << a << '\n';
	CMyData<double> b(5.5);
	cout << b << '\n';
	CMyData<char *> c("hello");
	cout << c << '\n';
}

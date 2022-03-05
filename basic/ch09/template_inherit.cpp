#include "../ch01/stdafx.h"

template<typename T>
class CMyData
{
	public:
	protected:
		T m_data;
};

template<typename T>
class CMyDataEx : public CMyData<T>
{
	public:
		T get_data() const { return m_data; }
		void set_data(T param) { m_data = param; }
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyDataEx<int> a;
	a.set_data(5);
	cout << a.get_data() << '\n';
}

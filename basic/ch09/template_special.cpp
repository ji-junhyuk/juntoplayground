#include "../ch01/stdafx.h"

template<typename T>
class CMyData
{
	CMyData(T param) : m_data(param) { }
	T get_data() const { return m_data; }
	void set_data(T param) { m_data = param; }
	private:
	T m_data;
};

template< >
class CMyData<char*>
{
	public:
	CMyData(char *p_size_param)
	{
		int i_len = strlen(p_size_param);
		m_data = new char[i_len + 1];
	}
	~CMyData() { delete[] m_data; }
	char* get_data() const { return m_data; }
	private:
	char *m_data;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData<char*> a("hello");
	cout << a.get_data() << '\n';
	return (0);
}

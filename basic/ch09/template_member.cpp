#include "../ch01/stdafx.h"

template<typename T>
class CTest
{
	public:
		CTest();
		T test_func();
	protected:
		static T m_data;
};

template<typename T>
CTest<T>::CTest()
{
}

template<typename T>
T CTest<T>::test_func()
{
	return m_data;
}

template<typename T>
T CTest<T>::m_data = 15;

int _tmain(int argc, _TCHAR *argv[])
{
	CTest<double> a;
	cout << a.test_func() << '\n';
	return (0);
}

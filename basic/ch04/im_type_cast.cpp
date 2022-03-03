#include "../ch01/stdafx.h"

class CTestData
{
	public:
		explicit CTestData(int i_param) : m_i_data(i_param)
	{
		cout << "CTestData(int)" << '\n';
	}
		~CTestData()
		{
			cout << "~CTestData()" << '\n';
		}
		CTestData(const CTestData &rhs) : m_i_data(rhs.m_i_data)
	{
		cout << "CTestData(cosnt CTestData &)" << '\n';
	}
		int get_data() const { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
};

void test_func(const CTestData &param)
{
	cout << "test_func(): " << param.get_data() << '\n';
}

int _tmain(int argc, _TCHAR *argv[])
{
	test_func(5); // 컴파일러에 의해 test_func(CTestData(5)); 랑 동일.
	// test_func(CTestData 형식), 그런데 인자 5가 들어왔다. CTestData가 int 자료형에 대한 <변환 생성자>를 제공한 덕분에 test_func함수의 매개변수인 param은 param(5)의 형태로 생성되었다.
	// 컴파일러는 '알아서' 임시 객체를 생성한 후 이 임시 객체에 대한 참조가 test_func()함수로 전달되도록 했다. 이 임시객체는 test_fun() 함수를 반환함과 동시에 소멼키ㅕㅆ다.
}

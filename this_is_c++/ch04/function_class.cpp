#include "../ch01/stdafx.h"

class CTestData
{
	public:
		CTestData(int i_param) : m_i_data(i_param)
	{
		cout << "CTestData(int)" << '\n';
	}
//		CTestData(const CTestData &rhs) = delete;
		CTestData(const CTestData &rhs) : m_i_data(rhs.m_i_data)
	{
		cout << "CTestData(const CTestData &)" << '\n';
	}
		int get_data() const { return m_i_data; }
		void set_data(int i_param) { m_i_data = i_param; }
	private:
		int m_i_data = 0;
};

void	test_func(const CTestData &param)
{
	cout << "test_func()" << '\n';
	// 피 호출자 함수에서 매개변수 인스턴스의 값을 변경할 수 없다.
	param.set_data(20);
}

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "===========begin===========" << '\n';
	CTestData a(10);
	test_func(a);
	cout << "a: " << a.get_data() << '\n';
}
/*
 * 문법적으로 아무 문제가 없는 코드지만
 * 이 함수를 호출하기 위해 main 함수에 CTestData 객체를 2개나 생성햇으며 함수가 호출될 때 매개변수인 param은 호출자 a를 원본으로 두고 복사본이 생성된다.
 */

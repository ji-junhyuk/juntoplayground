#include "../ch01/stdafx.h"
#include <iostream>

using namespace std;

class CMyData
{
	int m_i_data;

	CMyData() {}; //생성자함수 private으로 오류
	public:
	int get_data(void)
	{
		return m_i_data;
	}
	void set_data(int i_param)
	{
		m_i_data = i_param;
	}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData data;
	data.set_data(10);
	cout << data.get_data() << '\n';
	return (0);
}

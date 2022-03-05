#include "../ch01/stdafx.h"
#include <memory>
#include <iostream>

class CMyData
{
	public:
		CMyData() { cout << "CMyData()" << '\n'; }
		~CMyData() { cout << "~CMyData()" << '\n'; }
};

int _tmain(int argc, _TCHAR *argv[])
{
	cout << "====begin====" << '\n';
	{
	//	auto_ptr<CMyData>ptr_test(new CMyData);
		auto_ptr<CMyData>ptr_test(new CMyData[3]);
	}
	cout << "====end====" << '\n';
}

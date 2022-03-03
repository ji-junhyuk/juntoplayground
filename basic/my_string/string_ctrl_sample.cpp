#include "../ch01/stdafx.h"
#include "my_string.h"

//void test_func(CMyString &param) // 'const char *CMyString::get_string(void)': 'this' 포인터를 'const CMyString'에서 'CMyString &'(으)로 변 환할 수 없습니다.
//{
//	cout << param.get_string() << '\n';
//}
//
//int _tmain(int argc, _TCHAR *argv[])
//{
//	CMyString str_data;
//	str_data.set_string("hello");
////	cout << str_data.get_string() << '\n';
//	test_func(str_data);
//}

CMyString test_func(void)
{
	CMyString str_test("test_func() return");
	cout << str_test << '\n';
	return str_test;
}

int _tmain(int argc, _TCHAR *argv[])
{
	test_func();
	return 0;
}

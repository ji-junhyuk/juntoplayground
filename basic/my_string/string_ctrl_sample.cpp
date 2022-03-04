#include "../ch01/stdafx.h"
#include "my_string_ex.h"

int _tmain(int argc, _TCHAR *argv[])
{
	CMyStringEx str_test;
	str_test.set_string("멍멍이아들");
	cout << str_test << '\n';
}
//int _tmain(int argc, _TCHAR *argv[])
//{
//	CMyStringEx str_left("hello"), str_right("world");
//	cout << str_left + str_right << '\n';
//	return (0);
//}
/*
int _tmain(int argc, _TCHAR *argv[])
{
	CMyStringEx str_test;
	str_test.set_string("I am a boy.");
	cout << str_test << '\n';

	int i_index = str_test.find("am");
	cout << "i_index: " << i_index << '\n';
	return (0);
}
*/
//int _tmain(int argc, _TCHAR *argv[])
//{
//	CMyStringEx str_test;
//	str_test.set_string("멍멍이아들");
//	cout << str_test << '\n';
//	str_test.set_string("hello");
//	cout << str_test << '\n';
//}
//int _tmain(int argc, _TCHAR *argv[])
//{
//	CMyString str_left("test"), str_right("string");
//	if (str_left == str_right)
//		cout << "same" << '\n';
//	else
//		cout << "different" << '\n';
//	str_left = CMyString("string");
//	if (str_left == str_right)
//		cout << "same" << '\n';
//	else
//		cout << "different" << '\n';
//	return (0);
//}
//void test_func(const CMyString &str_param)
//{
//	cout << str_param[0] << '\n';
//	cout << str_param[str_param.get_length() - 1] << '\n';
//}
//
//int _tmain(int argc, _TCHAR *argv[])
//{
//	CMyString str_param("HelloWorld");
//	cout << str_param << '\n';
//	test_func(str_param);
//}

//int _tmain(int argc, _TCHAR *argv[])
//{
//	CMyString str_left("hello"), str_right("world"), str_result;
//	str_result = str_left + str_right;
//	cout << str_result << '\n';
//	cout << str_left << '\n';
//	str_left += CMyString("world");
//	cout << str_left << '\n';
//	return (0);
//}


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


/*
CMyString test_func(void)
{
	CMyString str_test("test_func() return");
	cout << str_test << '\n';
	return str_test;
}
*/

//int _tmain(int argc, _TCHAR *argv[])
//{
//	test_func();
//	return 0;
//}

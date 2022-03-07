#include "../ch01/stdafx.h"
#include "my_string_ex.h"

CMyStringEx::CMyStringEx()
{
}

CMyStringEx::CMyStringEx(const char *p_size_param)
	: CMyString(p_size_param)
{
}

CMyStringEx::~CMyStringEx()
{
}

int CMyStringEx::find(const char *p_size_param)
{
	if (p_size_param == NULL || get_string() == NULL)
		return -1;
	const char *p_size_result = strstr(get_string(), p_size_param);
	if (p_size_result != NULL)
		return p_size_result - get_string();
	return -1;
}

int CMyStringEx::set_string(const char *p_size_param)
{
	int i_result;

	if (strcmp(p_size_param, "멍멍이아들") == 0)
		i_result = CMyString::set_string("착한사람");
	else
		i_result = CMyString::set_string(p_size_param);
	return i_result;
}

void CMyStringEx::on_set_string(char *p_size_data, int i_length)
{
	if (strcmp(p_size_data, "멍멍이아들") == 0)
		strcpy_s(p_size_data, sizeof(char) * (i_length + 1), "*착한아들*");
}

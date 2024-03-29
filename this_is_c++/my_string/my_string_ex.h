#pragma once
#include "my_string.h"

class CMyStringEx
	:public CMyString
{
	public:
		CMyStringEx();
		CMyStringEx(const char *p_size_param);
		~CMyStringEx();
		int find(const char *p_size_param);
		int set_string(const char *p_size_param);
		void on_set_string(char *p_size_data, int i_length);
};

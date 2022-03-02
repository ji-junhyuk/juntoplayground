#pragma once
#include <cstddef>
#include <string>

class CMyString
{
	public:
		CMyString();
		~CMyString();
	private:
		char *m_p_c_size_data;
		int m_i_length;
	public:
		int set_string(const char *p_size_param);
		const char *get_string();
		void release();
};

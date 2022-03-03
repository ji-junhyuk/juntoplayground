#pragma once
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

class CMyString
{
	public:
		CMyString();
		explicit CMyString(const char *p_size_param);
		CMyString(const CMyString &rhs);
		CMyString(CMyString &&rhs);
		~CMyString();
	private:
		char *m_p_c_size_data;
		int m_i_length;
	public:
		int set_string(const char *p_size_param);
		const char *get_string() const;
		void release();
		CMyString& operator=(const CMyString &rhs);
		operator char *() const
		{
			return m_p_c_size_data;
		}
};

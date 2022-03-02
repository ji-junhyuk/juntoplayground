#include "my_string.h"

CMyString::CMyString()
	: m_p_c_size_data(NULL)
	  , m_i_length(0)
{
}

CMyString::~CMyString()
{
	release();
}

int CMyString::set_string(const char *p_size_param)
{
	release();
	if (p_size_param == NULL)
		return (0);
	int i_length = strlen(p_size_param);
	if (i_length == 0)
		return (0);
	m_p_c_size_data = new char[i_length + 1];
	strcpy_s(m_p_c_size_data, sizeof (char ) * (i_length + 1), p_size_param);
	m_i_length = i_length;
	return i_length;
}

const char *CMyString::get_string()
{
	return m_p_c_size_data;
}

void CMyString::release()
{
	if (m_p_c_size_data != NULL)
		delete[] m_p_c_size_data;
	m_p_c_size_data = NULL;
	m_i_length = 0;
}

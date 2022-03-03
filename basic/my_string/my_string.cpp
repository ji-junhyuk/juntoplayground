#include "my_string.h"

CMyString::CMyString()
	: m_p_c_size_data(NULL)
	  , m_i_length(0)
{
}

CMyString::CMyString(const CMyString &rhs)
	: m_p_c_size_data(NULL)
	  , m_i_length(0)
{
	this->set_string(rhs.get_string());
}

CMyString::CMyString(CMyString &&rhs)
	: m_p_c_size_data(NULL)
	  , m_i_length(0)
{
	cout << "CMyString 이동 생성자 호출" << '\n';
	m_p_c_size_data = rhs.m_p_c_size_data;
	m_i_length = rhs.m_i_length;

	rhs.m_p_c_size_data = NULL;
	rhs.m_i_length = 0;
}

CMyString::CMyString(const char *p_size_param)
	: m_p_c_size_data(NULL)
	  , m_i_length(0)
{
	set_string(p_size_param);
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

const char *CMyString::get_string() const
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

CMyString &CMyString::operator=(const CMyString &rhs)
{
	if (this != &rhs)
		this->set_string(rhs.get_string());
	return *this;
}

int CMyString::get_length() const
{
	return m_i_length;
}

int CMyString::append(const char *p_size_param)
{
	if (p_size_param == NULL)
		return 0;
	int i_len_param = strlen(p_size_param);
	if (i_len_param == 0)
		return 0;
	if (m_p_c_size_data == NULL)
	{
		set_string(p_size_param);
		return m_i_length;
	}
	int i_len_cur = m_i_length;
	char *p_size_result = new char[i_len_cur + i_len_param + 1];
	strcpy_s(p_size_result, sizeof(char) * (i_len_cur + 1), m_p_c_size_data);
	strcpy_s(p_size_result + (sizeof(char) * i_len_cur), sizeof(char) * (i_len_param + 1), p_size_param);
	release();
	m_p_c_size_data = p_size_result;
	m_i_length = i_len_cur + i_len_param;
	return m_i_length;
}

CMyString CMyString::operator+(const CMyString &rhs)
{
	CMyString str_result(m_p_c_size_data);
	str_result.append(rhs.get_string());
	return str_result;
}

CMyString &CMyString::operator+=(const CMyString &rhs)
{
	append(rhs.get_string());
	return *this;
}

char &CMyString::operator[](int i_index)
{
	return m_p_c_size_data[i_index];
}

char CMyString::operator[](int i_index) const
{
	return m_p_c_size_data[i_index];
}

int CMyString::operator==(const CMyString &rhs)
{
	if (m_p_c_size_data != NULL && rhs.m_p_c_size_data != NULL)
		if (strcmp(m_p_c_size_data, rhs.m_p_c_size_data) == 0)
			return 1;
	return 0;
}

int CMyString::operator!=(const CMyString &rhs)
{
	if (m_p_c_size_data != NULL && rhs.m_p_c_size_data != NULL)
		if (strcmp(m_p_c_size_data, rhs.m_p_c_size_data) == 0)
			return 0;
	return 1;
}

#include "file_stream.h"

CFileStream::CFileStream() :
	m_p_file(NULL),
	m_i_file_size(0),
	m_b_open(false)
{
}

CFileStream::~CFileStream()
{
	close();
}

bool CFileStream::open(char *p_file_name, char *p_mode)
{
	if (m_b_open)
		return false;
	fopen_s(&m_p_file, p_file_name, p_mode);
	if (!m_p_file)
		return false;
	fseek(m_p_file, 0, SEEK_END);
	//ftell :파일 커서의 위치를 얻어오는 함수이다. 
	m_i_file_size = ftell(m_p_file);
	fseek(m_p_file, 0, SEEK_SET);
	m_b_open = true;
	return true;
}

bool CFileStream::close()
{
	if (!m_b_open)
		return false;
	m_b_open = false;
	fclose(m_p_file);
	m_p_file = NULL;
	m_i_file_size = 0;
	return true;
}

void CFileStream::read(void *p_data, int i_size)
{
	if (!m_b_open)
		return ;
	fread(p_data, i_size, 1, m_p_file);
}

void CFileStream::read_line(void *p_data, int &i_size)
{
	if (!m_b_open)
		return ;
	char c_data;
	char *p_change_data = (char *)p_data;
	i_size = 0;
	while (feof(m_p_file) == 0)
	{
		fread(&c_data, 1, 1, m_p_file);
		if (c_data == '\n')
			break ;
		p_change_data[i_size] = c_data;
		++i_size;
	}
}

void CFileStream::write(void *p_data, int i_size)
{
	if (!m_b_open)
		return ;
	fwrite(p_data, i_size, 1, m_p_file);
}

void CFileStream::write_line(void *p_data, int i_size)
{
	if (!m_b_open)
		return ;
	char *p_buffer = new char[i_size + 1];
	*(p_buffer + i_size) = '\n';
	fwrite(p_buffer, i_size + 1, 1, m_p_file);
	delete[] p_buffer;
}

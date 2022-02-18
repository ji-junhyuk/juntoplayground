#pragma once

#include "value.h"

class CFileStream
{
	public:
		CFileStream();
		~CFileStream();
	private:
		FILE	*m_p_file;
		int		m_i_file_size;
		bool	m_b_open;
	public:
		bool open(char *p_file_name, char *p_mode);
		bool close();
		void read(void *p_data, int i_size);
		void read_line(void *p_data, int &i_size);
		void write(void *p_data, int i_size);
};

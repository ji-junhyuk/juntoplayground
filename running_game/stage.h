#pragma once

#include "value.h"

class CStage
{
	public:
		CStage();
		~CStage();
	private:
		char m_c_stage[10][50];
		POINT m_t_start;
		POINT m_t_end;
	public:
		POINT get_start()
		{
			return m_t_start;
		}
		POINT get_end()
		{
			return m_t_end;
		}
	public:
		bool init();
		bool init(char *p_file_name);
		void render();
};

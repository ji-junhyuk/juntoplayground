#pragma once

#include "value.h"

class CStage
{
	public:
		CStage();
		~CStage();
	private:
		char m_c_stage[10][50];
	public:
		bool init();
		bool init(char *p_file_name);
		void render();
};

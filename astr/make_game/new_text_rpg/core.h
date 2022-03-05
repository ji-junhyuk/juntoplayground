#pragma once

#include "value.h"

class CCore
{
	private:
		LEVELUPINFO m_t_level_up_info
	public:
		bool init();
		void run();
	private:
		int output_menu();
	DECLARE_SINGLE(CCore)
};

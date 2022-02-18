#pragma once

#include "value.h"

class CCore
{
	private:
		CCore();
		~CCore();
	private:
		static CCore *m_p_inst;
	public:
		static CCore *get_inst();
		static void destroy_inst();
	public:
		bool init();
		void run();
};

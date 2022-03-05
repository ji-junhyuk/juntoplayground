#pragma once

#include "value.h"

class CCore
{
	private:
		CCore();
		~CCore();
	private:
		static CCore* m_p_inst;
	public:
		static CCore* get_inst()
		{
			if (!m_p_inst)
				m_p_inst = new CCore;
			return m_p_inst;
		}
		static void destroy_inst()
		{
			SAFE_DELETE(m_p_inst);
		}
	public:
		bool init();
		void run();
};

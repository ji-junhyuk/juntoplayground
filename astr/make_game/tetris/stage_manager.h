#pragma once

#include "value.h"

class CStageManager
{
	private:
		CStageManager();
		~CStageManager();
	private:
		static CStageManager* m_p_inst;
	public:
		static CStageManager* get_inst()
		{
			if (!m_p_inst)
				m_p_inst = new CStageManager;
			return m_p_inst;
		}
		static void destroy_inst()
		{
			SAFE_DELETE(m_p_inst);
		}
	private:
		class CStage*	m_p_cur_stage;
	public:
		class CStage* get_current_stage() const
		{
			return m_p_cur_stage;
		}
	public:
		bool init();
		void run();
};

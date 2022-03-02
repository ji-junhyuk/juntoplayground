#pragma once

#include "value.h"

enum STAGE_TYPE
{
	ST_NONE,
	ST_EASY,
	ST_NORMAL,
	ST_HARD,
	ST_BACK
};

class CStageManager
{
	private:
		vector<class CStage*> m_vec_stage;
		enum MENU
		{
			MENU_NONE,
			MENU_EASY,
			MENU_NORMAL,
			MENU_HARD,
			MENU_BACK
		};
	public:
		bool init();
		void run();
	private:
		bool create_stage(STAGE_TYPE e_type);
		int	output_menu();
	DECLARE_SINGLE(CStageManager)
};

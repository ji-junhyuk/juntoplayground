#pragma once

#include "value.h"

class CStage
{
	private:
		CStage();
		~CStage();
	private:
		friend class CStageManager;
	private:
		char m_stage[STAGE_HEIGHT][STAGE_WIDTH];
	private:
		bool init();
		void render();
};

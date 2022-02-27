#pragma once
#include "stage.h"
class CStageEasy :
	public CStage
{
	public:
		CStageEasy();
		~CStageEasy();
	public:
		virtual bool init();
		virtual void run();
};

#pragma once
#include "stage.h"
class CStageHard :
	public CStage
{
	public:
		CStageHard();
		~CStageHard();
	public:
		virtual bool init();
		virtual void run();
};

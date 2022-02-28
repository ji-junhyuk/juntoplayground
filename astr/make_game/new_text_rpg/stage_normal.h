#pragma once
#include "stage.h"
class CStageNormal :
	public CStage
{
	public:
		CStageNormal();
		~CStageNormal();
	public:
		virtual bool init();
		virtual void run();
};

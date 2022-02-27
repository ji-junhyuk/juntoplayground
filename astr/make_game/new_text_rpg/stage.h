#pragma once

#include "value.h"

class CStage
{
	public:
		CStage();
		virtual ~CStage();
	public:
		virtual bool init() = 0;
		virtual void run() = 0;
};

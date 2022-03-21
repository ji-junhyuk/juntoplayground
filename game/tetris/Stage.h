#pragma once

#include "value.h"

class Stage
{
private:
	Stage();
	~Stage();

private:
	friend class StageManager;

private:
	char	m_Stage[STAGE_HEIGHT][STAGE_WIDTH];
public:
	bool Init();
	void Render();
};


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
	int		m_iSpeed;

public:
	int GetSpeed()	const
	{
		return m_iSpeed;
	}
	
	void SetSpeed(int iSpeed)
	{
		m_iSpeed = iSpeed;
	}

public:
	void AddBlock(class Shape* pShape, const POSITION& tPos);
	bool CheckBlock(int x, int y);

public:
	bool Init();
	void Render();
};


#pragma once

#include "value.h"

class StageManager
{
private:
	StageManager();
	~StageManager();

private:
	static StageManager* m_pInst;

public:
	static StageManager* GetInst()
	{
		if (!m_pInst)
			m_pInst = new StageManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

private:
	class Stage* m_pCurStage;

public:
	class Stage* GetCurrentStage() const
	{
		return m_pCurStage;
	}
public:
	bool Init();
	void Run();
};


#include "StageManager.h"
#include "Stage.h"

StageManager* StageManager::m_pInst = NULL;

StageManager::StageManager()	:
	m_pCurStage(NULL)
{
}

StageManager::~StageManager()
{
}

bool StageManager::Init()
{
	m_pCurStage = new Stage;
	
	if (!m_pCurStage->Init())
		return false;

	return true;
}

void StageManager::Run()
{
	m_pCurStage->Render();
}

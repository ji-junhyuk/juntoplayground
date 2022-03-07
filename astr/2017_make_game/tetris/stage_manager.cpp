#include "stage_manager.h"
#include "stage.h"

CStageManager* CStageManager::m_p_inst = NULL;
CStageManager::CStageManager()	:
	m_p_cur_stage(NULL)
{
}

CStageManager::~CStageManager()
{
}

bool CStageManager::init()
{
	m_p_cur_stage = new CStage;
	if (!m_p_cur_stage->init())
		return false;
	return true;
}

void CStageManager::run()
{
	m_p_cur_stage->render();
}

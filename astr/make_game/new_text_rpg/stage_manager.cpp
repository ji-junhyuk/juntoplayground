#include "stage_manager.h"
#include "stage_easy.h"
#include "stage_normal.h"
#include "stage_hard.h"

DEFINITION_SINGLE(CStageManager)

CStageManager::CStageManager()
{
}

CStageManager::~CStageManager()
{
	safe_delete_vec_list(m_vec_stage);
}

bool CStageManager::init()
{
	if (!create_stage(ST_EASY))
		return false;
	if (!create_stage(ST_NORMAL))
		return false;
	if (!create_stage(ST_HARD))
		return false;
	return true;
}

void CStageManager::run()
{
	m_vec_stage[0]->run();
}

bool CStageManager::create_stage(STAGE_TYPE e_type)
{
	CStage *p_stage = NULL;
	switch (e_type)
	{
		case ST_EASY:
			p_stage = new CStageEasy;
			break;
		case ST_NORMAL:
			p_stage = new CStageNormal;
			break;
		case ST_HARD:
			p_stage = new CStageHard;
			break;
	}
	if (!p_stage->init())
	{
		SAFE_DELETE(p_stage);
		return false;
	}
	m_vec_stage.push_back(p_stage);
	return true;
}

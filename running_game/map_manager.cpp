#include "map_manager.h"
#include "stage.h"

CMapManager * CMapManager::m_p_inst = NULL;

CMapManager::CMapManager()
{
	for (int idx = 0; idx < STAGE_MAX_COUNT; ++idx)
	{
		m_p_stage[idx] = NULL;
	}
}

CMapManager::~CMapManager()
{
	for (int idx = 0; idx < STAGE_MAX_COUNT; ++idx)
	{
		safe_delete(m_p_stage[idx]);
	}
}

CMapManager *CMapManager::get_inst()
{
	if (!m_p_inst)
		m_p_inst = new CMapManager;
	return m_p_inst;
}

void CMapManager::destroy_inst()
{
	safe_delete(m_p_inst);
}

bool CMapManager::init()
{
	char *p_stage_file[3] = {"stage1.txt", "stage2.txt", "stage3.txt"};
	for (int idx = 0; idx < STAGE_MAX_COUNT; ++idx)
	{
		m_p_stage[idx] = new CStage;
		if (!m_p_stage[idx]->init(p_stage_file[idx]))
			return false;
	}
	return true;
}

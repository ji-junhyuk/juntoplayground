#include "core.h"
#include "stage_manager.h"

CCore *CCore::m_p_inst = NULL;

CCore::CCore()
{
}

CCore::~CCore()
{
	CStageManager::destroy_inst();
}

bool CCore::init()
{
	if (!CStageManager::get_inst()->init())
		return false;
	return true;
}

void CCore::run()
{
	CStageManager::get_inst()->run();
}

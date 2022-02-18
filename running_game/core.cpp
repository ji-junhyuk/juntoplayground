#include "core.h"
#include "map_manager.h"

CCore *CCore::m_p_inst = NULL;

CCore::CCore()
{
}

CCore::~CCore()
{
	CMapManager::destroy_inst();
}

CCore *CCore::get_inst()
{
	if (!m_p_inst)
		m_p_inst = new CCore;
	return m_p_inst;
}

void CCore::destroy_inst()
{
	safe_delete(m_p_inst);
}

bool CCore::init()
{
	if (!CMapManager::get_inst()->init())
		return false;
	return true;
}

void CCore::run()
{
}

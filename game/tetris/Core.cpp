#include "Core.h"
#include "StageManager.h"

Core* Core::m_pInst = NULL;

Core::Core()
{
}

Core::~Core()
{
	StageManager::DestroyInst();
}

bool Core::Init()
{
	if (!StageManager::GetInst()->Init())
		return false;
	return true;
}

void Core::Run()
{
	StageManager::GetInst()->Run();
}

#include "pch.h"
#include "CSceneTool.h"

#include "CKeyMgr.h"

CSceneTool::CSceneTool()
{
}

CSceneTool::~CSceneTool()
{
}

void CSceneTool::update()
{
	CScene::update();

	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}

void CSceneTool::Enter()
{
}

void CSceneTool::Exit()
{
}
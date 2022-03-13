#include "pch.h"
#include "CSceneMgr.h"
#include "CSceneStart.h"

CSceneMgr::CSceneMgr()
	: m_arrScene{}
	, m_pCurScene(nullptr)
{

}

CSceneMgr::~CSceneMgr()
{
	for (UINT idx = 0; idx < (UINT)SCENE_TYPE::END; ++idx)
	{
		if (m_arrScene[idx] != nullptr)
			delete m_arrScene[idx];
	}
}

void CSceneMgr::init()
{
	// Scene 생성
	m_arrScene[(UINT)SCENE_TYPE::START] = new CSceneStart;
	m_arrScene[(UINT)SCENE_TYPE::START]->SetName(L"Start Scene");
	//m_arrScene[(UINT)SCENE_TYPE::TOOL] = new CSceneTool;
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_01] = new CSceneStage01;
	//m_arrScene[(UINT)SCENE_TYPE::STAGE_02] = new CSceneStage02;
	// 현재 씬 지정
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
	m_pCurScene->Enter();
}

void CSceneMgr::update()
{
	m_pCurScene->update();
	m_pCurScene->finalupdate();
}

void CSceneMgr::render(HDC _dc)
{
	m_pCurScene->render(_dc);
}

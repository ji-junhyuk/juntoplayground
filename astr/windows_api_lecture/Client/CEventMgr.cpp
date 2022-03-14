#include "pch.h"
#include "CEventMgr.h"
#include "CObject.h"
#include "CSceneMgr.h"
#include "CScene.h"

CEventMgr::CEventMgr()
{

}

CEventMgr::~CEventMgr()
{

}

void CEventMgr::update()
{
	// ================================================
	// 이전 프레임에서 등록해둔 Dead Object를 삭제한다.
	// ================================================
	for (size_t idx = 0; idx < m_vecEvent.size(); ++idx)
	{
		delete m_vecDead[idx];
	}
	m_vecDead.clear();
	// ===========
	// 이벤트 처리
	// ===========
	for (size_t idx = 0; idx < m_vecEvent.size(); ++idx)
	{
		Excute(m_vecEvent[idx]);
	}
	m_vecEvent.clear();
}

void CEventMgr::Excute(const tEvent& _eve)
{
	switch (_eve.eEven)
	{
	case EVENT_TYPE::CREATE_OBJECT:
	{
		// lParam : Obejct Address
		// wParam : Group Type
		CObject* pNewObj = (CObject*)_eve.lParam;
		GROUP_TYPE eType = (GROUP_TYPE)_eve.wParam;
		CSceneMgr::GetInst()->GetCurScene()->AddObject(pNewObj, eType);
	}
		break;
	case EVENT_TYPE::DELETE_OBJECT:
	{
		// Object를 Dead 상태로 변경
		// 삭제예정 오브젝트들을 모아둔다.
		CObject* pDeadObj = (CObject*)_eve.lParam;
		pDeadObj->SetDead();
		m_vecDead.push_back(pDeadObj);
	}
		break;
	case EVENT_TYPE::SCENE_CHANGE:
	{
		CSceneMgr::GetInst()->ChangeScene((SCENE_TYPE)_eve.lParam);
	}

		break;
	}
}

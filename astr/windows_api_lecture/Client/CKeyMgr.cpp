#include "pch.h"
#include "CKeyMgr.h"
#include "CCore.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
    'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'Z',
	'X',
	'C',
	'V',
	'B',
	VK_MENU,
	VK_CONTROL,
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE,
	VK_LBUTTON,
	VK_RBUTTON,

};

CKeyMgr::CKeyMgr()
{
}
CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::init()
{
	for (int idx = 0; idx < (int)KEY::LAST; ++idx)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyMgr::update()
{
	// 윈도우 포커싱 알아내기
	// HWND hMainWnd = CCore::GetInst()->GetMainHwnd();
	HWND hWnd = GetFocus();

	// 윈도우 포커싱 중일 때 키 이벤트 동작
	if (nullptr != hWnd)
	{
		for (int idx = 0; idx < (int)KEY::LAST; ++idx)
		{
			// 키가 눌려있다
			if (GetAsyncKeyState(g_arrVK[idx]) & 0x8000)
			{
				if (m_vecKey[idx].bPrevPush)
				{
					m_vecKey[idx].eState = KEY_STATE::HOLD;
				}
				else
				{
					m_vecKey[idx].eState = KEY_STATE::TAP;
				}
				m_vecKey[idx].bPrevPush = true;
			}
			else
			{
				if (m_vecKey[idx].bPrevPush)
				{
					m_vecKey[idx].eState = KEY_STATE::AWAY;
				}
				else
				{
					m_vecKey[idx].eState = KEY_STATE::NONE;
				}
				m_vecKey[idx].bPrevPush = false;
			}
		}
		POINT ptPos = {};
		GetCursorPos(&ptPos);
		ScreenToClient(CCore::GetInst()->GetMainHwnd(), &ptPos);
		m_vCurMousePos = Vec2((float)ptPos.x, (float)ptPos.y);
	}
	else
	{
		for (int idx = 0; idx < (int)KEY::LAST; ++idx)
		{
			m_vecKey[idx].bPrevPush = false;
			if (m_vecKey[idx].eState == KEY_STATE::TAP || m_vecKey[idx].eState == KEY_STATE::HOLD)
			{
				m_vecKey[idx].eState = KEY_STATE::AWAY;
			}
			else if (m_vecKey[idx].eState == KEY_STATE::AWAY)
			{
				m_vecKey[idx].eState = KEY_STATE::NONE;
			}
		}
	}

}


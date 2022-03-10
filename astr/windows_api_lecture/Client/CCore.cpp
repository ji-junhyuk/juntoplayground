#include "pch.h"
#include "CCore.h"
#include "CObject.h"

// CCore* CCore::g_pInst = nullptr;

CObject g_obj;


CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDc(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDc);
}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;
	RECT rt = {0, 0, m_ptResolution.x, m_ptResolution.y};
	// 해상도에 맞게 윈도우 크기 조정
	AdjustWindowRect(&rt, WS_OVERLAPPED, true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDc = GetDC(m_hWnd);
	g_obj.m_ptPos = POINT{ m_ptResolution.x / 2, m_ptResolution.y / 2 };
	g_obj.m_ptScale = POINT{ 100, 100 };
	return S_OK;
}

void CCore::progress()
{
	static int callcount = 0;
	++callcount;
	static int iPrevCount = GetTickCount();
	int iCurCount = GetTickCount();
	if (iCurCount - iPrevCount > 1000)
	{
		iPrevCount = iCurCount;
		callcount = 0;
	}
	update();
	render();

}

void CCore::update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		g_obj.m_ptPos.x -= 1;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		g_obj.m_ptPos.x += 1;
	}
}

void CCore::render()
{
	Rectangle(m_hDc, g_obj.m_ptPos.x - g_obj.m_ptScale.x / 2,
		g_obj.m_ptPos.y - g_obj.m_ptScale.y / 2,
		g_obj.m_ptPos.x + g_obj.m_ptScale.x / 2,
		g_obj.m_ptPos.y + g_obj.m_ptScale.y / 2);
}

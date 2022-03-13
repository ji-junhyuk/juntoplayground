#include "pch.h"
#include "CPathMgr.h"
#include "CCore.h"

CPathMgr::CPathMgr()
	: m_szContentPath{}
{
}

CPathMgr::~CPathMgr()
{

}

void CPathMgr::init()
{
	GetCurrentDirectory(255, m_szContentPath);
	int iLen = wcslen(m_szContentPath);
	for (int idx = iLen - 1; idx >= 0; --idx)
	{
		if (m_szContentPath[idx] == '\\')
		{
			m_szContentPath[idx] = '\0';
			break;
		}
	}
	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");
	//SetWindowText(CCore::GetInst()->GetMainHwnd(), m_szContentPath);
}

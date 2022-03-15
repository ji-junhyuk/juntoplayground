#include "pch.h"
#include "CSceneTool.h"

#include "CKeyMgr.h"
#include "CTile.h"

#include "CCore.h"
#include "CResMgr.h"

CSceneTool::CSceneTool()
{
}

CSceneTool::~CSceneTool()
{
}

void CSceneTool::Enter()
{
	CTexture* pTileTex = CResMgr::GetInst()->LoadTexture(L"Tile", L"texture\\tile\\TILE.bmp");
	for (int idx = 0; idx < 5; ++idx)
	{
		for (int jdx = 0; jdx < 5; ++jdx)
		{
			CTile* pTile = new CTile();
			pTile->SetPos(Vec2((float)(jdx * TILE_SIZE), (float)(idx * TILE_SIZE)));
			pTile->SetTexture(pTileTex);
			AddObject(pTile, GROUP_TYPE::TILE);
		}
	}
	Vec2 vResolution = CCore::GetInst()->GetResolution();
	CCamera::GetInst()->SetLookAt(vResolution / 2.f);
}

void CSceneTool::update()
{
	CScene::update();
}

void CSceneTool::Exit()
{
}

INT_PTR CALLBACK TileCountProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
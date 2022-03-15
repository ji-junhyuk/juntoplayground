#include "pch.h"
#include "CTile.h"

#include "CTexture.h"

CTile::CTile()
	: m_pTileTax(nullptr)
	, m_iIdx(47)
{
	SetScale(Vec2(TILE_SIZE, TILE_SIZE));
}

CTile::~CTile()
{
}

void CTile::update()
{
}

void CTile::render(HDC _dc)
{
	if (m_pTileTax == nullptr || m_iIdx == -1)
		return;
	UINT iWidth = m_pTileTax->Width();
	UINT iHeight = m_pTileTax->Height();

	UINT iMaxCol = iWidth / TILE_SIZE;
	UINT iMaxRow = iHeight / TILE_SIZE;

	UINT iCurRow = (UINT)m_iIdx / iMaxCol;
	UINT iCurCol = (UINT)m_iIdx % iMaxCol;

	if (iCurRow >= iMaxRow)
		assert(nullptr);
	Vec2 vRenderPos = CCamera::GetInst()->GetRenderPos(GetPos());
	Vec2 vScale = GetScale();

	BitBlt(_dc
		, int(vRenderPos.x)
		, int(vRenderPos.y)
		, int(vScale.x)
		, int(vScale.y)
		, m_pTileTax->GetDC()
		, iCurCol * TILE_SIZE
		, iCurRow * TILE_SIZE
		, SRCCOPY);
}

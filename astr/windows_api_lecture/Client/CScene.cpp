#include "pch.h"
#include "CScene.h"

#include "CObject.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	for (UINT idx = 0; idx < (UINT)GROUP_TYPE::END; ++idx)
	{
		for (size_t jdx = 0; jdx < m_arrObj[idx].size(); ++jdx)
		{
			//m_arrObj[idx] 그룹 벡터의 j 물체 삭제
			delete m_arrObj[idx][jdx];
		}
	}
}

void CScene::update()
{
	for (UINT idx = 0; idx < (UINT)GROUP_TYPE::END; ++idx)
	{
		for (size_t jdx = 0; jdx < m_arrObj[idx].size(); ++jdx)
		{
			m_arrObj[idx][jdx]->update();
		}
	}
}

void CScene::render(HDC _dc)
{
	for (UINT idx = 0; idx < (UINT)GROUP_TYPE::END; ++idx)
	{
		for (size_t jdx = 0; jdx < m_arrObj[idx].size(); ++jdx)
		{
			m_arrObj[idx][jdx]->render(_dc);
		}
	}
}

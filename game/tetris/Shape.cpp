#include "Shape.h"
#include "Core.h"
#include "Stage.h"
#include "StageManager.h"

Shape::Shape()
{
	m_iDir = RD_UP;
	m_iWidthCount = 0;

	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			m_cShape[idx][jdx] = '1';
		}
	}
}

Shape::~Shape()
{
}

bool Shape::Init()
{
	m_tPivot.x = 0;
	m_tPivot.y = 3;
	
	return true;
}

void Shape::Rotation()
{
}

void Shape::Render()
{
	for (int idx = 0; idx < 4; ++idx)
	{
		int iYIndex = m_tPos.y - (3 - idx);
		if (iYIndex < 0)
			continue;
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_tPos.x + jdx >= STAGE_WIDTH)
				continue;
			if (m_cShape[idx][jdx] == '0')
			{
				Core::GetInst()->SetConsolePos(m_tPos.x + jdx, iYIndex);
				cout << "бс";
			}
		}
		cout << '\n';
	}
}

void Shape::RenderNext()
{
	for (int idx = 0; idx < 4; ++idx)
	{
		int iYIndex = m_tPos.y - (3 - idx);
		if (iYIndex < 0)
			continue;
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_cShape[idx][jdx] == '0')
			{
				Core::GetInst()->SetConsolePos(m_tPos.x + jdx, iYIndex);
				cout << "бс";
			}
		}
	}
}

bool Shape::MoveDown()
{
	Stage* pStage = StageManager::GetInst()->GetCurrentStage();
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_cShape[idx][jdx] == '0')
			{
				if (pStage->CheckBlock(m_tPos.x + jdx, m_tPos.y - (2 - idx)))
				{
					for (int kdx = 0; kdx < 4; ++kdx)
					{
						for (int ldx = 0; ldx < 4; ++ldx)
						{
							if (m_cShape[kdx][ldx] == '0')
							{
								if (m_tPos.y - (3 - kdx) < 0)
								{
									Core::GetInst()->End();
									break;
								}
							}
						}
					}
					return true;
				}
			}
		}
	}
	++m_tPos.y;
	return false;
}

void Shape::MoveLeft()
{
	if (m_tPos.x == 0)
		return;
	Stage* pStage = StageManager::GetInst()->GetCurrentStage();
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_cShape[idx][jdx] == '0')
			{
				if (pStage->CheckBlock(m_tPos.x + jdx - 1, m_tPos.y - (3 - idx)))
					return;
			}
		}
	}
	--m_tPos.x;
}

void Shape::MoveRight()
{
	if (m_tPos.x + m_iWidthCount == STAGE_WIDTH)
		return;
	Stage* pStage = StageManager::GetInst()->GetCurrentStage();
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_cShape[idx][jdx] == '0')
			{
				if (pStage->CheckBlock(m_tPos.x + jdx + 1, m_tPos.y - (3 - idx)))
					return;
			}
		}
	}
	++m_tPos.x;
}

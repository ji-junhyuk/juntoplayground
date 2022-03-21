#include "Stage.h"
#include "Core.h"
#include "Shape.h"

Stage::Stage() :
	m_iSpeed(2)
{
}

Stage::~Stage()
{
}

void Stage::AddBlock(Shape* pShape, const POSITION& tPos)
{
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (pShape->GetBlock(jdx, idx) == '0')
			{
				m_Stage[tPos.y - (3 - idx)][tPos.x + jdx] = '0';
				bool bLine = true;
				for (int kdx = 0; kdx < STAGE_WIDTH; ++kdx)
				{
					if (m_Stage[tPos.y - (3 - idx)][kdx] != '0')
					{
						bLine = false;
						break;
					}
				}
				if (bLine)
				{
					for (int kdx = tPos.y - (3 - idx); kdx > 0; --kdx)
					{
						for (int ldx = 0; ldx < STAGE_WIDTH; ++ldx)
						{
							m_Stage[kdx][ldx] = m_Stage[kdx - 1][ldx];
						}
					}
				}
			}
		}
	}
}

bool Stage::CheckBlock(int x, int y)
{
	if (y >= STAGE_HEIGHT)
		return true;
	else if (x < 0 || x >= STAGE_WIDTH)
		return true;

	return m_Stage[y][x] == '0';
}

bool Stage::Init()
{
	for (int idx = 0; idx < STAGE_HEIGHT; ++idx)
	{
		for (int jdx = 0; jdx < STAGE_WIDTH; ++jdx)
		{
			m_Stage[idx][jdx] = '1';
		}
	}
	return true;
}

void Stage::Render()
{
	for (int idx = 0; idx < STAGE_HEIGHT + 1; ++idx)
	{
		for (int jdx = 0; jdx < STAGE_WIDTH + 2; ++jdx)
		{
			if (idx == 0 && (jdx == 0 || jdx == STAGE_WIDTH + 1))
				cout << "бс";
			else if (jdx == 0)
				cout << "бс";
			else if (idx == STAGE_HEIGHT)
				cout << "бс";
			else if (jdx == STAGE_WIDTH + 1)
				cout << "бс";
			else
			{
				if (m_Stage[idx][jdx - 1] == '1')
					cout << "  ";
				else
					cout << "бс";
			}
		}
		cout << '\n';
	}
	for (int idx = 0; idx < 7; ++idx)
	{
		Core::GetInst()->SetConsolePos(17, idx);
		cout << "бс";
	}
	for (int idx = 0; idx < 6; ++idx)
	{
		Core::GetInst()->SetConsolePos(11 + idx, 6);
		cout << "бс";
	}
}

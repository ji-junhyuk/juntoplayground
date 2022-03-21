#include "Shape.h"
#include "Core.h"

Shape::Shape()
{
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

void Shape::Render()
{
	for (int idx = 0; idx < 4; ++idx)
	{
		Core::GetInst()->SetConsolePos(m_tPos.x, m_tPos.y - (3 - idx));
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_cShape[idx][jdx] == '0')
				cout << "бс";
			else
				cout << "  ";
		}
	}
}

void Shape::MoveDown()
{
	if (m_tPos.y == STAGE_HEIGHT - 1)
		return ;
	++m_tPos.y;
}

void Shape::MoveLeft()
{
	if (m_tPos.x == 0)
		return ;
	--m_tPivot.x;
}

void Shape::MoveRight()
{
	if (m_tPos.x + m_iWidthCount == STAGE_WIDTH)
		return;
	++m_tPivot.x;
}

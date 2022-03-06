#include "shape.h"

CShape::CShape()
{
	m_i_width_count = 0;
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			m_c_shape[idx][jdx] = '1';
		}
	}
}

CShape::~CShape()
{
}

bool CShape::init()
{
	m_t_pivot.x = 0;
	m_t_pivot.y = 3;
	return true;
}

void CShape::render()
{
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_c_shape[idx][jdx] == '0')
				cout << "■";
			else
				cout << "  ";
		}
		cout << '\n';
	}
}

void CShape::move_down()
{
	if (m_t_pos.y == STAGE_HEIGHT - 1)
		return ;
		++m_t_pos.y;
}

void CShape::move_left()
{
	if (m_t_pos.x == 0)
		return ;
	--m_t_pos.x;
}

void CShape::move_right()
{
	if (m_t_pos.x + m_i_width_count == STAGE_WIDTH)
		return ;
	++m_t_pos.x;
}

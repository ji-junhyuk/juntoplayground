#include "shape_line.h"

CShapeLine::CShapeLine()
{
}

CShapeLine::~CShapeLine()
{
}

bool CShapeLine::init()
{
	if (!CShape::init())
		return false;
	m_c_shape[3][0] = '0';
	m_c_shape[3][1] = '0';
	m_c_shape[3][2] = '0';
	m_c_shape[3][3] = '0';
	m_i_width_count = 4;
	m_t_pos.x = 4;t
	m_t_pos.y = 0;
	m_i_dir = RD_DOWN;
	return true;
}

void CShapeGun::rotation()
{
	m_i_dir = m_i_dir == RD_DOWN ? RD_UP : RD_DOWN;
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			m_c_shape[idx][jdx] = '1';
		}
	}
	switch (m_i_dir)
	{
		case RD_UP:
		m_c_shape[0][3] = '0';
		m_c_shape[1][3] = '0';
		m_c_shape[2][3] = '0';
		m_c_shape[3][3] = '0';
			break;
		case RD_DOWN:
		m_c_shape[3][0] = '0';
		m_c_shape[3][1] = '0';
		m_c_shape[3][2] = '0';
		m_c_shape[3][3] = '0';
			break;
	}
}

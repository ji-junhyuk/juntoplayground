#include "shape_r_gun.h"

CShapeRGun::CShapeRGun()
{
}

CShapeRGun::~CShapeRGun()
{
}

bool CShapeRGun::init()
{
	if (!CShape::init())
		return false;
	m_c_shape[2][0] = '0';
	m_c_shape[2][1] = '0';
	m_c_shape[2][2] = '0';
	m_c_shape[3][0] = '0';
	m_i_width_count = 3;
	m_t_pos.x = 4;
	m_t_pos.y = 0;
	m_i_dir = RD_RIGHT;
	return true;
}

void CShapeGun::rotation()
{
	++m_i_dir;
	m_i_dir %= RD_END;
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
		m_c_shape[1][0] = '0';
		m_c_shape[2][0] = '0';
		m_c_shape[3][0] = '0';
		m_c_shape[3][1] = '0';
			break;
		case RD_RIGHT:
		m_c_shape[2][0] = '0';
		m_c_shape[2][1] = '0';
		m_c_shape[2][2] = '0';
		m_c_shape[3][0] = '0';
			break;
		case RD_DOWN:
		m_c_shape[1][0] = '0';
		m_c_shape[1][1] = '0';
		m_c_shape[2][1] = '0';
		m_c_shape[3][1] = '0';
			break;
		case RD_LEFT:
		m_c_shape[3][0] = '0';
		m_c_shape[3][1] = '0';
		m_c_shape[3][2] = '0';
		m_c_shape[2][2] = '0';
			break;
	}
}

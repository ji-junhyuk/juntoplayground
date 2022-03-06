#include "shape_gun.h"

CShapeT::CShapeT()
{
}

CShapeT::~CShapeT()
{
}

bool CShapeT::init()
{
	if (!CShape::init())
		return false;
	m_c_shape[2][0] = '0';
	m_c_shape[2][1] = '0';
	m_c_shape[2][2] = '0';
	m_c_shape[3][1] = '0';
	m_i_width_count = 3;
	m_t_pos.x = 4;t
	m_t_pos.y = 0;
	return true;
}

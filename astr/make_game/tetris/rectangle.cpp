#include "rectange.h"

CRectangle::CRectangle()
{
}

CRectangle::~CRectangle()
{
}

bool CRectangle::init()
{
	if (!CShape::init())
		return false;
	m_c_shape[2][0] = '0';
	m_c_shape[2][1] = '0';
	m_c_shape[3][0] = '0';
	m_c_shape[3][1] = '0';
	m_i_width_count = 2;
	return true;
}


#include "Rect.h"

Rect::Rect()
{
}

Rect::~Rect()
{
}

bool Rect::Init()
{
	if (!Shape::Init())
		return false;
	m_cShape[2][0] = '0';
	m_cShape[2][1] = '0';
	m_cShape[3][0] = '0';
	m_cShape[3][1] = '0';
	
	m_iWidthCount = 2;
	m_tPos.x = 4;
	m_tPos.y = 0;
	return true;
}

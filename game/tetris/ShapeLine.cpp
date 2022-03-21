#include "ShapeLine.h"

ShapeLine::ShapeLine()
{
}

ShapeLine::~ShapeLine()
{
}

bool ShapeLine::Init()
{
	if (!Shape::Init())
		return false;
	m_cShape[3][0] = '0';
	m_cShape[3][1] = '0';
	m_cShape[3][2] = '0';
	m_cShape[3][3] = '0';

	m_iWidthCount = 4;
	m_tPos.x = 4;
	m_tPos.y = 0;
	m_iDir = RD_DOWN;
	return true;
}

void ShapeLine::Rotation()
{
	m_iDir = m_iDir == RD_DOWN ? RD_UP : RD_DOWN;

	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			m_cShape[idx][jdx] = '1';
		}
	}
	switch (m_iDir)
	{
	case RD_UP:
		m_cShape[0][0] = '0';
		m_cShape[1][0] = '0';
		m_cShape[2][0] = '0';
		m_cShape[3][0] = '0';
		m_iWidthCount = 1;
		break;
	case RD_DOWN:
		m_cShape[3][0] = '0';
		m_cShape[3][1] = '0';
		m_cShape[3][2] = '0';
		m_cShape[3][3] = '0';
		m_iWidthCount = 4;
		break;
	}
}

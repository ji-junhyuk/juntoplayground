#include "stage.h"
#include "core.h"
#include "shape.h"

CStage::CStage()	:
	m_i_speed(2)
{
}

CStage::~CStage()
{
}

void CStage::add_block(CStage* p_shape, const POSITION& t_pos)
{
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (p_shape->get_block(jdx, idx) == '0')
			{
				m_stage[t_pos.y - (3 - idx)][t_pos.x + jdx] = '0';
			}
		}
	}
}

bool check_block(int x, int y)
{
	if (y >= STAGE_HEIGHT)
		return true;
	else if (x < 0 || x >= STAGE_WIDTH)
		return true;
	return m_stage[y][x] == '0';
}

bool CStage::init()
{
	for (int idx = 0; idx < STAGE_HEIGHT; ++idx)
	{
		for (int jdx = 0; jdx < STAGE_WIDTH; ++jdx)
		{
			m_c_shape[idx][jdx] = '1';
		}
	}
	return true;
}

void CStage::render()
{
	for (int idx = 0; idx < STAGE_HEIGHT + 1; ++idx)
	{
		for (int jdx = 0; jdx < STAGE_WIDTH + 2; ++jdx)
		{
			if (idx == 0 && (jdx == 0 || jdx == STAGE_WIDTH + 1))
				cout << "■";
			else if (jdx == 0)
				cout << "■";
			else if (idx == STAGE_HEIGHT)
				cout << "■";
			else if (jdx == STAGE_WIDTH + 1)
				cout << "■";
			else
			{
				if (m_stage[idx][jdx - 2] == '1')
					cout << " ";
				else
					cout << "■";
		}
		cout << '\n';
	}
	for (int idx = 0; idx < 7; ++idx)
	{
		CCore::get_inst()->set_console_pos(17, 0);
		cout << "■";
	}
	for (int idx = 0; idx < 6; ++idx)
	{
		CCore::get_inst()->set_console_pos(11 + idx, 6);
		cout << "■";
	}
}

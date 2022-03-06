#include "shape.h"
#include "core.h"
#include "stage.h"
#include "stage_manager.h"

CShape::CShape()
{
	m_e_dir = RD_UP;
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
		int i_y_index = m_t_pos.y - (3 - idx);
		if (i_y_index < 0)
			continue;
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_t_pos.x + jdx >= STAGE_WIDTH)
				continue;
			if (m_c_shape[idx][jdx] == '0')
			{
				CCore::get_inst()->SetConsolePos(m_t_pos.x + jdx, i_y_index);
				cout << "■";
			}
		}
		cout << '\n';
	}
}

void CShape::render_next()
{
	for (int idx = 0; idx < 4; ++idx)
	{
		int i_y_index = m_t_pos.y - (3 - idx);
		if (i_y_index < 0)
			continue;
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_c_shape[idx][jdx] == '0')
			{
				cout << "■";
				CCore::get_inst()->SetConsolePos(m_t_pos.x, i_y_index);
			}
			else
				cout << "  ";
		}
		cout << '\n';
	}
}

bool CShape::move_down()
{
	CShape *p_stage = CStageManager::get_inst()->get_current_stage();
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_c_shape[idx][jdx] == '0')
			{
				if (p_stage->check_block(m_t_pos.x + jdx, m_t_pos.y - (2 - idx)))
					return true;
			}
		}
	}
	++m_t_pos.y;
	return false;
}

void CShape::move_left()
{
	if (m_t_pos.x == 0)
		return ;
	CStage *p_stage = CStageManager::get_inst()->get_current_stage();
	for (int idx = 0; idx < 4; ++idx)
	{
		for (int jdx = 0; jdx < 4; ++jdx)
		{
			if (m_c_shape[idx][jdx] == '0')
			{
				if (p_stage->check_block(m_t_pos.x + jdx + 1, m_t_pos.y - (3 - idx)))
					return ;
			}
		}
	}
	--m_t_pos.x;
}

void CShape::move_right()
{
	if (m_t_pos.x + m_i_width_count == STAGE_WIDTH)
		return ;
	++m_t_pos.x;
}

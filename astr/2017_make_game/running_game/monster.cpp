#include "monster.h"
#include "stage.h"
#include "map_manager.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}

bool CMonster::init()
{
	m_t_pos.x = 0;
	m_t_pos.y = 0;
	m_i_dir = -1;
	m_i_speed = 3;
	m_i_frame_count = 0;
	return true;
}

void CMonster::update()
{
	++m_i_frame_count;
	if (m_i_frame_count == m_i_speed)
	{
		m_i_frame_count = 0;
		CStage *p_stage = CMapManager::get_inst()->get_stage();
		if (p_stage->get_block(m_t_pos.x + m_i_dir, m_t_pos.y + 1) != SBT_WALL)
		{
			m_i_dir *= -1;
		}
		else if (p_stage->get_block(m_t_pos.x + m_i_dir, m_t_pos.y) == SBT_WALL)
			m_i_dir *= -1;
		m_t_pos.x += m_i_dir;
	}
}

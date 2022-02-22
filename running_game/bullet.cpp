#include "bullet.h"
#include "stage.h"
#include "map_manager.h"
#include "monster.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

bool CBullet::init()
{
	m_t_pos.x = 0;
	m_t_pos.y = 0;
	m_i_dist = 8;
	return true;
}

void CBullet::update()
{
	CStage *p_stage = CMapManager::get_inst()->get_stage();
	POINT t_next_pos = m_t_pos;
	t_next_pos.x++;
	for (int idx = 0; idx < p_stage->get_monster_count(); ++idx)
	{
		CMonster *p_monster = p_stage->get_monster(idx);
		POINT t_monster_pos = p_monster->get_pos();
		if (t_monster_pos.x == m_t_pos.x && t_monster_pos.y == m_t_pos.y ||
				t_monster_pos.x == t_next_pos.x && t_monster_pos.y == t_next_pos.y)
		{
			p_stage->delete_monster(idx);
			m_i_dist = 0;
			return ;
		}
	}
	if (p_stage->get_block(m_t_pos.x + 1, m_t_pos.y) != SBT_WALL)
	{
		m_t_pos.x++;
		--m_i_dist;
	}
	else
	{
		m_i_dist = 0;
	}
	m_t_pos.x++;
	--m_i_dist;
}

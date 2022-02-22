#include "player.h"
#include "map_manager.h"
#include "stage.h"
#include "object_manager.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::init()
{
	m_t_pos.x = 0;
	m_t_pos.y = 8;
	m_b_jump = false;
	m_b_complete = false;
	m_i_jump_dir = JD_STOP;
	m_i_jump_state = 0;
	m_i_score = 0;
	m_b_bullet_fire = false;
	m_b_big_item = false;
	return true;
}

void CPlayer::update()
{
	CStage *p_stage = CMapManager::get_inst()->get_stage();
	if (GetAsyncKeyState('A') && 0x8000)
	{
		if (p_stage->get_block(m_t_pos.x - 1, m_t_pos.y) != SBT_WALL)
		{
			if (!m_b_big_item)
				--m_t_pos.x;
			else
			{
				if (p_stage->get_block(m_t_pos.x - 1, m_t_pos.y - 1) != SBT_WALL)
					--m_t_pos.x;
			}
			if (m_t_pos.x < 0)
				m_t_pos.x = 0;
		}
	}
	if (GetAsyncKeyState('D') && 0x8000)
	{
		if (p_stage->get_block(m_t_pos.x + 1, m_t_pos.y) != SBT_WALL)
		{
			if (!m_b_big_item)
				++m_t_pos.x;
			else
			{
				if (p_stage->get_block(m_t_pos.x + 1, m_t_pos.y - 1) != SBT_WALL)
					++m_t_pos.x;
			}
			if (m_t_pos.x >= BLOCK_X)
				m_t_pos.x = 49;
		}
	}
	if (GetAsyncKeyState(VK_SPACE) && 0x8000 && !m_b_jump)
	{
		m_b_jump = true;
		m_i_jump_dir = JD_UP;
		m_i_jump_state = 0;
	}
	int i_big_count = 1;
	if (m_b_big_item)
		i_big_count = 2;
	if (m_b_jump)
	{
		CStage *p_stage = CMapManager::get_inst()->get_stage();
		switch (m_i_jump_dir)
		{
			case JD_UP:
				++m_i_jump_state;
				if (m_i_jump_state > JUMP_BLOCK_MAX)
				{
					m_i_jump_state = JUMP_BLOCK_MAX;
					m_i_jump_dir = JD_DOWN;
				}
				else if (p_stage->get_block(m_t_pos.x, m_t_pos.y - i_big_count) == SBT_WALL)
				{
					--m_i_jump_state;
					int i_rand = rand() % 100;
					STAGE_BLOCK_TYPE e_block_type;
					if (i_rand < 30)
						e_block_type = SBT_ITEM_BULLET;
					else
						e_block_type = SBT_ITEM_BIG;
					p_stage->change_block(m_t_pos.x, m_t_pos.y - i_big_count, e_block_type);
					m_i_jump_dir = JD_DOWN;
				}
				else 
				{
					--m_t_pos.y;
				}
				break;
			case JD_DOWN:
				if (m_t_pos.y >= BLOCK_Y)
				{
					cout << "플레이어 사망" << '\n';
					system("pause");
					m_t_pos.y = BLOCK_Y - 1;
				}
				else if (p_stage->get_block(m_t_pos.x, m_t_pos.y + 1) == SBT_WALL)
				{
					m_i_jump_dir = JD_STOP;
					m_b_jump = false;
				}
				else 
					++m_t_pos.y;
				break;
		}
	}
	if (p_stage->get_block(m_t_pos.x, m_t_pos.y + 1) != SBT_WALL && !m_b_jump)
	{
		++m_t_pos.y;
	}
	STAGE_BLOCK_TYPE e_cur_block_type = (STAGE_BLOCK_TYPE)p_stage->get_block(m_t_pos.x, m_t_pos.y);
	STAGE_BLOCK_TYPE e_up_block_type = (STAGE_BLOCK_TYPE)p_stage->get_block(m_t_pos.x, m_t_pos.y - 1);
	if (e_cur_block_type == SBT_COIN || (e_up_block_type == SBT_COIN && m_b_big_item))
	{
		p_stage->change_block(m_t_pos.x, m_t_pos.y, SBT_ROAD);
		p_stage->change_block(m_t_pos.x, m_t_pos.y - 1, SBT_ROAD);
		m_i_score += 1000;
	}
	else if (e_cur_block_type == SBT_ITEM_BULLET || (e_up_block_type == SBT_ITEM_BULLET && m_b_big_item))
	{
		m_b_bullet_fire = true;
		p_stage->change_block(m_t_pos.x, m_t_pos.y, SBT_ROAD);
		p_stage->change_block(m_t_pos.x, m_t_pos.y - 1, SBT_ROAD);
	}
	else if (e_cur_block_type == SBT_ITEM_BIG || (e_up_block_type == SBT_ITEM_BIG && m_b_big_item))
	{
		m_b_big_item = true;
		p_stage->change_block(m_t_pos.x, m_t_pos.y, SBT_ROAD);
		p_stage->change_block(m_t_pos.x, m_t_pos.y - 1, SBT_ROAD);
	}
	else if (p_stage->get_block(m_t_pos.x, m_t_pos.y) == SBT_END || (e_up_block_type == SBT_END && m_b_big_item))
	{
		m_b_complete = true;
	}
	else if (p_stage->check_monster(m_t_pos.x, m_t_pos.y))
	{
		m_t_pos = p_stage->get_start();
		system("pause");
	}
	if (m_t_pos.y >= BLOCK_Y)
	{
		cout << "플레이어 사망" << '\n';
		m_t_pos = p_stage->get_start();
		reset();
		p_stage->reset_stage();
		system("pause");
		return ;
	}
	if (GetAsyncKeyState('G') & 0x8000 && m_b_bullet_fire)
	{
		POINT t_pos = m_t_pos;
		t_pos.x++;
		ObjectManager::get_inst()->create_bullet(t_pos);
	}
}

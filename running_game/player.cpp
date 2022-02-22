#include "player.h"
#include "map_manager.h"
#include "stage.h"

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
	m_i_jump_dir = JD_STOP;
	m_i_jump_state = 0;
	
	return true;
}

void CPlayer::update()
{
	CStage *p_stage = CMapManager::get_inst()->get_stage();
	if (GetAsyncKeyState('A') && 0x8000)
	{
		if (p_stage->get_block(m_t_pos.x - 1, m_t_pos.y) != SBT_WALL)
		{
			--m_t_pos.x;
			if (m_t_pos.x < 0)
				m_t_pos.x = 0;
		}
	}
	if (GetAsyncKeyState('D') && 0x8000)
	{
		if (p_stage->get_block(m_t_pos.x + 1, m_t_pos.y) != SBT_WALL)
		{
			++m_t_pos.x;
			if (m_t_pos.x >= 50)
				m_t_pos.x = 49;
		}
	}
	if (GetAsyncKeyState(VK_SPACE) && 0x8000 && !m_b_jump)
	{
		m_b_jump = true;
		m_i_jump_dir = JD_UP;
		m_i_jump_state = 0;
	}
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
				else if (p_stage->get_block(m_t_pos.x, m_t_pos.y - 1) == SBT_WALL)
				{
					--m_i_jump_state;
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
				if (p_stage->get_block(m_t_pos.x, m_t_pos.y + 1) == SBT_WALL)
				{
					m_i_jump_dir = JD_STOP;
					m_b_jump = false;
				}
				else 
				{
					++m_t_pos.y;
				}
				break;
		}
	}
}

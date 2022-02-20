#include "player.h"

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
	if (GetAsyncKeyState('A') && 0x8000)
	{
		--m_t_pos.x;
		if (m_t_pos.x < 0)
			m_t_pos.x = 0;
	}
	if (GetAsyncKeyState('D') && 0x8000)
	{
		++m_t_pos.x;
		if (m_t_pos.x >= 50)
			m_t_pos.x = 49;
	}
	if (GetAsyncKeyState(VK_SPACE) && 0x8000 && !m_b_jump)
	{
		m_b_jump = true;
		m_i_jump_dir = JD_UP;
		m_i_jump_state = 0;
	}
	if (m_b_jump)
	{
		switch (m_i_jump_dir)
		{
			case JD_UP:
				++m_i_jump_state;
				if (m_i_jump_state > JUMP_BLOCK_MAX)
				{
					m_i_jump_state = JUMP_BLOCK_MAX;
					m_i_jump_dir = JD_DOWN;
				}
				else 
				{
					--m_t_pos.y;
				}
				break;
			case JD_DOWN:
				--m_i_jump_state;
				if (m_
				break;
		}
	}
}

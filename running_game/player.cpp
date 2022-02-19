#include "player.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::init()
{
	m_i_x = 0;
	m_i_y = 8;
	m_b_jump = false;
	m_i_jump_dir = JD_STOP;
	m_i_jump_state = 0;
	
	return true;
}

void CPlayer::update()
{
	if (GetAsyncKeyState('A') && 0x8000)
	{
		--m_i_x;
		if (m_i_x < 0)
			m_i_x = 0;
	}
	if (GetAsyncKeyState('D') && 0x8000)
	{
		++m_i_x;
		if (m_i_x >= 50)
			m_i_x = 49;
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
					--m_i_y;
				}
				break;
			case JD_DOWN:
				break;
		}
	}
}

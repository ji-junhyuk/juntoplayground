#pragma once

#include "value.h"

class CMonster
{
	public:
		CMonster();
		~CMonster();
	private:
		POINT	m_t_pos;
		int		m_i_dir;
		int		m_i_speed;
		int		m_i_frame_count;
	public:
		void set_pos(int x, int y)
		{
			m_t_pos.x = x;
			m_t_pos.y = y;
		}
	public:
		POINT get_pos()
		{
			return m_t_pos;
		}
	public:
		bool init();
		void update();
};

#pragma once

#include "value.h"

class CBullet
{
	public:
		CBullet();
		~CBullet();
	private:
		POINT	m_t_pos;
		int		m_i_dist;
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
		bool get_enable()
		{
			return m_i_dist != 0;
		}
	public:
		bool init();
		void update();
};

#pragma once

#include "value.h"

class CShape
{
	public:
		CShape();
		virtual ~CShape();
	protected:
		char		m_c_shape[4][4];
		POSITION	m_t_pos;
		POSITION 	m_t_pivot;
		int			m_i_width_count;
	public:
		void set_position(int x, int y)
		{
			m_t_pos.x = x;
			m_t_pos.y = y;
		}
		void set_position(cosnt POSITION& t_pos)
		{
			m_t_pos = t_pos;
		}
		POSITION get_position() const
		{
			return m_t_pos;
		}
		POSITION get_pivot() const
		{
			return m_t_pivot;
		}
	public:
		virtual bool init();
	public:
		void render();
		void move_down();
		void move_left();
		void move_right();
};

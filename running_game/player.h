#pragma once
#pragma comment(lib, "User32.lib")

#include "value.h"
# define JUMP_BLOCK_MAX 2

enum JUMP_DIR
{
	JD_STOP,
	JD_UP,
	JD_DOWN
};

class CPlayer
{
	public:
		CPlayer();
		~CPlayer();
	private:
		POINT m_t_pos;
		bool m_b_jump;
		int m_i_jump_dir;
		int m_i_jump_state;
		int m_i_score;
		bool m_b_complete;
		bool m_b_bullet_fire;
		bool m_b_big_item;
	public:
		int get_x()
		{
			return m_t_pos.x;
		}
		int	get_y()
		{
			return m_t_pos.y;
		}
		int get_score()
		{
			return m_i_score;
		}
		bool get_complete()
		{
			return m_b_complete;
		}
		bool get_big_item_enable()
		{
			return m_b_big_item;
		}
	public:
		void reset()
		{
			m_b_complete = false;
			m_b_bullet_fire = false;
			m_b_big_item = false;
			m_i_score = 0;
		}
	public:
		void set_pos(int x, int y)
		{
			m_t_pos.x = x;
			m_t_pos.y = y;
		}
	public:
		bool init();
		void update();
};

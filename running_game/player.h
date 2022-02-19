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
		int	m_i_x;
		int m_i_y;
		bool m_b_jump;
		int m_i_jump_dir;
		int m_i_jump_state;
	public:
		void set_pos(int x, int y)
		{
			m_i_x = x;
			m_i_y = y;
		}
	public:
		int get_x()
		{
			return m_i_x;
		}
		int	get_y()
		{
			return m_i_y;
		}
	public:
		bool init();
		void update();
};

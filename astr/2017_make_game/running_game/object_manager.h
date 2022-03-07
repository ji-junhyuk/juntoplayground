#pragma once

#include "value.h"

class ObjectManager
{
	public:
		ObjectManager();
		~ObjectManager();
	private:
		static ObjectManager *m_p_inst;
	public:
		static ObjectManager *get_inst()
		{
			if (!m_p_inst)
				m_p_inst = new ObjectManager;
			return m_p_inst;
		}
		static void destroy_inst()
		{
			safe_delete(m_p_inst);
		}
	private:
		class CPlayer	*m_p_player;
		class CBullet	*m_p_bullet[BULLET_COUNT_MAX];
		int				m_i_cur_bullet_count;
	public:
		class CPlayer *get_player()
		{
			return m_p_player;
		}
	public:
		bool init();
		void update();
		bool create_bullet(POINT t_pos);
		bool check_bullet(int x, int y);
};

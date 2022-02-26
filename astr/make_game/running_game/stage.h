#pragma once

#include "value.h"

enum STAGE_BLOCK_TYPE
{
	SBT_WALL = '0',
	SBT_ROAD = '1',
	SBT_START = '2',
	SBT_END = '3',
	SBT_COIN = '4',
	SBT_ITEM_BULLET = '5',
	SBT_ITEM_BIG = '6',
	SBT_MONSTER = '7',
};

class CStage
{
	public:
		CStage();
		~CStage();
	private:
		char m_c_origin_stage[BLOCK_Y][BLOCK_X];
		char m_c_stage[BLOCK_Y][BLOCK_X];
		POINT m_t_start;
		POINT m_t_end;
		class CMonster**	m_p_monster_array;
		int					m_i_monster_count;	
		int					m_i_monster_array_count;
	public:
		POINT get_start()
		{
			return m_t_start;
		}
		POINT get_end()
		{
			return m_t_end;
		}
		char get_block(int x, int y)
		{
			return m_c_stage[y][x];
		}
		void change_block(int x, int y, STAGE_BLOCK_TYPE e_block)
		{
			m_c_stage[y][x] = e_block;
		}
		int get_monster_count()
		{
			return m_i_monster_count;
		}
		class CMonster *get_monster(int index)
		{
			return m_p_monster_array[index];
		}
		void delete_monster(int index)
		{
			delete m_p_monster_array[index];
			for (int idx = index; idx < m_i_monster_count - 1; ++idx) 
			{
				m_p_monster_array[idx] = m_p_monster_array[idx + 1];
			}
			m_p_monster_array[m_i_monster_count - 1] = NULL;
			--m_i_monster_count;
		}
	public:
		bool init();
		bool init(char *p_file_name);
		void update();
		void render();
		void reset_stage();
		class CMonster *create_monster(int x, int y);
		bool check_monster(int x, int y);
};

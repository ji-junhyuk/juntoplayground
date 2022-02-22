#pragma once

#include "value.h"

enum STAGE_BLOCK_TYPE
{
	SBT_WALL = '0',
	SBT_ROAD = '1',
	SBT_START = '2',
	SBT_END = '3',
	SBT_COIN = '4'
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
	public:
		bool init();
		bool init(char *p_file_name);
		void render();
		void reset_stage();
};

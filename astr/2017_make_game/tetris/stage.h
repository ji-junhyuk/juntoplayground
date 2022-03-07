#pragma once

#include "value.h"

class CStage
{
	private:
		CStage();
		~CStage();
	private:
		friend class CStageManager;
	private:
		char m_stage[STAGE_HEIGHT][STAGE_WIDTH];
		int m_i_speed;
	public:
		int get_speed() const
		{
			return m_i_speed;
		}
		void set_speed(int i_speed)
		{
			m_i_speed = i_speed;
		}
	public:
		void add_block(class CShape* p_shape, const POSITION& t_pos);
		bool check_block(int x, int y);
	private:
		bool init();
		void render();
};

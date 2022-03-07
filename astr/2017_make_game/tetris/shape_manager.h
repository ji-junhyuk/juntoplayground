#pragma once

#include "value.h"

class CShapeManager
{
	public:
		CShapeManager();
		~CShapeManager();
	private:
		static CShapeManager* m_p_inst;
	public:
		static CShapeManager* get_inst()
		{
			if (!m_p_inst)
				m_p_inst = new CShapeManager;
			return m_p_inst;
		}
		static void destroy_inst()
		{
			SAFE_DELETE(m_p_inst);
		}
	private:
		class CShape* m_p_cur_shape;
		class CShape& m_p_next_shape;
		int	m_i_speed;
	public:
		void update();
		void render();
		class CShape* create_random_shape();
		class CShape* create_shape(SHAPE_TYPE e_type);
};

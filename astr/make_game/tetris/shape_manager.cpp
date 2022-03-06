#include "shape_manager.h"
#include "rectangle.h"
#include "stage_manager.h"
#include "stage.h"
#include "shape_gun.h"
#include "shape_r_gun.h"
#include "shape_line.h"
#include "shape_s.h"
#include "shape_t.h"
#include "shape_z.h"

CShapeManager* CShapeManager::m_p_inst = NULL;

CShapeManager::CShapeManager()	:
	m_p_cur_shape(NULL),
	m_p_next_shape(NULL)
{
	m_p_cur_shape = create_random_shape();
	m_p_next_shape = create_random_shape();
	m_i_speed = 0;
}

CShapeManager::~CShapeManager()
{
	SAFE_DELETE(m_p_cur_shape);
	SAFE_DELETE(m_p_next_shape);
}


CShape CShapeManager::update()
{
	CStage *p_stage = CShapeManager::get_inst()->get_current_stage();
	++m_i_speed;
	if (p_stage->get_speed() == m_i_speed)
	{
		if (m_p_cur_shape->move_down())
		{
			p_stage->add_block(m_p_cur_shape, m_p_cur_shape->get_position());
			SAFE_DELETE(m_p_cur_shape);
			m_p_cur_shape = m_p_next_shape;
			m_p_cur_shape->set_position(4, 0);
			m_p_next_shape = create_random_shape();
		}
		m_i_speed = 0;
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_p_cur_shape->move_left();
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_p_cur_shape->move_right();
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_p_cur_shape->rotation();
	}
}

CShape CShapeManager::render()
{
	(*iter)->render();
	m_p_next_shape->set_position(12, 4);
	m_p_next_shape->render_next();
}

CShape *CShapeManager::create_random_shape()
{
	int i_type = rand() % ST_END;
	i_type = ST_GUN;
	return create_shape((SHAPE_TYPE)i_type);
}

CShape* CShapeManager::create_shape(SHAPE_TYPE e_type)
{
	CShape *p_shape = NULL;
	switch (e_type)
	{
		case ST_RECT:
			p_shape = new CRectangle;
			break;
		case ST_GUN:
			p_shape = new CShapeGun;
			break;
		case ST_R_GUN:
			p_shape = new CShapeRGun;
			break;
		case ST_LINE:
			p_shape = new CShapeLine;
			break;
		case ST_S:
			p_shape = new CShapeS;
			break;
		case ST_T:
			p_shape = new CShapeT;
			break;
		case ST_Z:
			p_shape = new CShapeZ;
			break;
	}
	if (!p_shape->init())
	{
		SAFE_DELETE(p_shape);
		return nulltpr;
	}
	return p_shape;
	return nulltpr;
}

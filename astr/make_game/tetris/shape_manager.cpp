#include "shape_manager.h"
#include "rectangle.h"

CShapeManager* CShapeManager::m_p_inst = NULL;

CShapeManager::CShapeManager()	:
	m_p_cur_shape(NULL),
	m_p_next_shape(NULL)
{
	m_p_cur_shape = create_random_shape();

}

CShapeManager::~CShapeManager()
{
	list<CShape*>::iterator iter_end = m_shape_list.end();
	for (list<CShape*>::iterator iter = m_shape_list.begin(); iter != iter_end; ++iter)
	{
		SAFE_DELETE(*iter);
	}
	SAFE_DELETE(m_p_cur_shape);
	SAFE_DELETE(m_p_next_shape);
}


CShape CShapeManager::update()
{
	m_p_cur_shape->move_down();
}

CShape CShapeManager::render()
{
	list<CShape*>::iterator iter_end = m_shape_list.end();
	for (list<CShape*>::iterator iter = m_shape_list.begin(); iter != iter_end; ++iter)
	{
		(*iter)->render();
	}
	m_p_cur_shape->render();
}

CShape *CShapeManager::create_random_shape()
{
	int i_type = rand() % ST_END;

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
	}
	if (!p_shape->init())
	{
		SAFE_DELETE(p_shape);
		return nulltpr;
	}
	return p_shape;
	return nulltpr;
}

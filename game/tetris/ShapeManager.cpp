#include "ShapeManager.h"
#include "Rect.h"

ShapeManager* ShapeManager::m_pInst = NULL;

ShapeManager::ShapeManager()	:
	m_pCurShape(NULL),
	m_pNextShape(NULL)
{
	m_pCurShape = CreateRandomShape();
}

ShapeManager::~ShapeManager()
{
	list<Shape*>::iterator iterEnd = m_pShapeList.end();
	for (list<Shape*>::iterator iter = m_pShapeList.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(*iter);
	}
	SAFE_DELETE(m_pCurShape);
	SAFE_DELETE(m_pNextShape);
}

void ShapeManager::Update()
{
	m_pCurShape->MoveDown();
}

void ShapeManager::Render()
{
	list<Shape*>::iterator iterEnd = m_pShapeList.end();
	for (list<Shape*>::iterator iter = m_pShapeList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render();
	}
	m_pCurShape->Render();
}

Shape* ShapeManager::CreateRandomShape()
{
	int	iType = rand() % ST_END;

	return CreateShape((SHAPE_TYPE)iType);
}

Shape* ShapeManager::CreateShape(SHAPE_TYPE eType)
{
	Shape* pShape = NULL;

	switch (eType)
	{
	case ST_RECT:
		pShape = new Rect;
		break;
	}
	if (!pShape->Init())
	{
		SAFE_DELETE(pShape);
		return NULL;
	}
	return pShape;
}

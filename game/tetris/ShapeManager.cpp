#include "ShapeManager.h"
#include "Rect.h"
#include "ShapeGun.h"
#include "ShapeLine.h"
#include "ShapeRGun.h"
#include "ShapeS.h"
#include "ShapeT.h"
#include "ShapeZ.h"
#include "StageManager.h"
#include "Stage.h"

ShapeManager* ShapeManager::m_pInst = NULL;

ShapeManager::ShapeManager()	:
	m_pCurShape(NULL),
	m_pNextShape(NULL)
{
	m_pCurShape = CreateRandomShape();
	m_pNextShape = CreateRandomShape();
	m_iSpeed = 0;
}

ShapeManager::~ShapeManager()
{
	SAFE_DELETE(m_pCurShape);
	SAFE_DELETE(m_pNextShape);
}

void ShapeManager::Update()
{
	Stage* pStage = StageManager::GetInst()->GetCurrentStage();
	++m_iSpeed;
	if (pStage->GetSpeed() == m_iSpeed)
	{
		if (m_pCurShape->MoveDown())
		{
			pStage->AddBlock(m_pCurShape, m_pCurShape->GetPosition());
			SAFE_DELETE(m_pCurShape);
			m_pCurShape = m_pNextShape;
			m_pCurShape->SetPosition(4, 0);
			m_pNextShape = CreateRandomShape();
		}
		m_iSpeed = 0;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_pCurShape->MoveLeft();
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_pCurShape->MoveRight();
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_pCurShape->Rotation();
	}
}

void ShapeManager::Render()
{
	m_pCurShape->Render();
	m_pNextShape->SetPosition(12, 4);
	m_pNextShape->RenderNext();
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
	case ST_GUN:
		pShape = new ShapeGun;
		break;
	case ST_RGUN:
		pShape = new ShapeRGun;
		break;
	case ST_LINE:
		pShape = new ShapeLine;
		break;
	case ST_S:
		pShape = new ShapeS;
		break;
	case ST_T:
		pShape = new ShapeT;
		break;
	case ST_Z:
		pShape = new ShapeZ;
		break;
	}
	if (!pShape->Init())
	{
		SAFE_DELETE(pShape);
		return NULL;
	}
	return pShape;
}

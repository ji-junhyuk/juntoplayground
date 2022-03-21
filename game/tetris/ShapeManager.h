#pragma once

#include "value.h"

class ShapeManager
{
private:
	ShapeManager();
	~ShapeManager();
private:
	static ShapeManager* m_pInst;
public:
	static ShapeManager* GetInst()
	{
		if (!m_pInst)
			m_pInst = new ShapeManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
private:
	class Shape*		m_pCurShape;
	class Shape*		m_pNextShape;
	int					m_iSpeed;
public:
	void Update();
	void Render();
	class Shape* CreateRandomShape();
	class Shape* CreateShape(SHAPE_TYPE eType);
};


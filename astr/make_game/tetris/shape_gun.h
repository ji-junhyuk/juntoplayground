#pragma once
#include "shape.h"
class CShapeGun	:
	public CShape
{
	public:
		CShapeGun();
		~CShapeGun();
	public:
		virtual bool init();
		virtual void rotation();
};

#pragma once
#include "shape.h"
class CRectangle	:
	public CShape
{
	public:
		CRectangle();
		~CRectangle();
	public:
		virtual bool init();
};

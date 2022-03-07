#pragma once
#include "shape.h"
class CShapeLine	:
	public CShape
{
	public:
		CShapeLine();
		~CShapeLine();
	public:
		virtual bool init();
};

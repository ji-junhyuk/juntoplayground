#include "pch.h"
#pragma once

// #define Add(a, b)	(a + b)
// i_cal = 10 * ADD(10, 20) 일 때 120. 예상과 다르게 작동한다. 10 * 10 + 20

#define SINGLE(type) public: static type* GetInst() { static type mgr; return &mgr; }
//static CCore* GetInst()
//{
//	static CCore core;
//
//	return &core;
//}
#pragma once

#include <iostream>
#include <time.h>

using namespace std;

#include "macro.h"
# define STAGE_WIDTH	10
# define STAGE_HEIGHT	15

typedef struct _tag_position
{
	int x;
	int y;
	_tag_position()	:
		x(0),
		y(0)
	{
	}
	_tag_position(const _tag_position& pos)
	{
		*this = pos;
	}
	_tag_position(int _x, int _y) :
		x(_x),
		y(_y)
	{
	}
	_tag_position operator +(const _tag_position& pos)
	{
		_tag_position	p;
		p.x = x + pos.x;
		p.y = y + pos.y;
		return p;
	}
	_tag_position operator +(int idx)
	{
		_tag_position	p;
		p.x = x + idx;
		p.y = y + idx;
		return p;
	}
	void operator +=(const _tag_position& pos)
	{
		x += pos.x;
		y += pos.y;
	}
	void operator +=(int idx)
	{
		x += idx;
		y += idx;
	}
	_tag_position operator -const _tag_position& pos)
	{
		_tag_position	p;
		p.x = x - pos.x;
		p.y = y - pos.y;
		return p;
	}
	_tag_position operator -int idx)
	{
		_tag_position	p;
		p.x = x - idx;
		p.y = y - idx;
		return p;
	}
	void operator -=(const _tag_position& pos)
	{
		x -= pos.x;
		y -= pos.y;
	}
	void operator -=(int idx)
	{
		x -= idx;
		y -= idx;
	}
	void operator =(const _tag_position& pos)
	{
		x = pos.x;
		y = pos.y;
	}
}POSITION, *PPOSITION;

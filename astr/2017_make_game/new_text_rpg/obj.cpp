#include "obj.h"

CObj::CObj()
{
}

CObj::CObj(const CObj &obj)
{
	m_str_name = obj.m_str_name;
	m_e_type = obj.m_e_type;
}

CObj::~CObj()
{
}

OBJECT_TYPE CObj::get_object_type() const
{
	return m_e_type;
}

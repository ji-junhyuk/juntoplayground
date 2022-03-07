#include "item.h"

CItem::CItem()
{
}

CItem::CItem(const CItem &item)	:
	CObj(item)
{
	m_t_info = item.m_t_info;
}

CItem::~CItem()
{
}

void CItem::set_item_info(ITEM_TYPE e_type, int i_price, int i_sell, char *p_desc)
{
	m_t_info.e_type = e_type;
	switch (e_type)
	{
		case IT_WEAPON:
			m_t_info.str_type_name = "무기";
			break;
		case IT_ARMOR:
			m_t_info.str_type_name = "방어구";
			break;
	}
	m_t_info.i_price = i_price;
	m_t_info.i_sell = i_sell;
	m_t_info.str_desc = p_desc;
}

bool CItem::init()
{
	return false;
}

void CItem::render()
{
}

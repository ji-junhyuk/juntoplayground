#include "item_armor.h"

CItemArmor::CItemArmor()
{
}

CItemArmor::CItemArmor(const CItemArmor &item)	:
	CItem(item)
{
	m_i_armor_min = item.m_i_armor_min;
	m_i_armor_max = item.m_i_armor_max;
}

CItemArmor::~CItemArmor()
{
}

bool CItemArmor::init()
{
}

void CItemArmor::render()
{
	cout << "이름 : " << m_str_name << "\t종류 : " << m_t_info.str_type_name << '\n';
	cout << "방어력 : " << m_i_armor_min << " ~ " << m_i_armor_max;
	cout << "Price : " << m_t_info.i_price << "\tSell : " << m_t_info.i_sell << '\n';
	cout << "설명 : " << m_t_info.str_desc << '\n';
}

CItemArmor *CItemArmor::clone()
{
	return new CItemArmor(*this);
}

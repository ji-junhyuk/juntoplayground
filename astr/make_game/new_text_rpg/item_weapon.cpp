#include "item_weapon.h"

CItemWeapon::CItemWeapon()
{
}

CItemWeapon::CItemWeapon(const CItemWeapon &item)	:
	CItem(item)
{
	m_i_attack_min = item.m_i_attack_min;
	m_i_attack_max = item.m_i_attack_max;
	m_f_critical = item.m_f_critical;
}

CItemWeapon::~CItemWeapon()
{
}

bool CItemWeapon::init()
{
	return true;
}

void CItemWeapon::render()
{
	cout << "이름 : " << m_str_name << "\t종류 : " << m_t_info.str_type_name << '\n';
	cout << "공격력 : " << m_i_attack_min << " ~ " << m_i_attack_max << "\t치명타율 : " << m_f_critical << '\n';
	cout << "Price : " << m_t_info.i_price << "\tSell : " << m_t_info.i_sell << '\n';
	cout << "설명 : " << m_t_info.str_desc << '\n';
}

CItemWeapon *CItemWeapon::clone()
{
	return new CItemWeapon(*this);
}

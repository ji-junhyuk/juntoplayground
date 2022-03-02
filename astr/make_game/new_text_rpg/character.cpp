#include "character.h"

CCharacter::CCharacter()
{
}

CCharacter::CCharacter(const CCharacter &character)	:
	CObj(character)
{
	m_t_info = character.m_t_info;
}

CCharacter::~CCharacter()
{
}

void CCharacter::set_character_info(int i_at_min, int i_at_max, int i_ar_min, int i_ar_max, int i_hp, int i_mp, int i_level, int i_exp)
{
	m_t_info.i_at_min = i_at_min;
	m_t_info.i_at_max = i_at_max;
	m_t_info.i_ar_min = i_ar_min;
	m_t_info.i_ar_max = i_ar_max;
	m_t_info.i_hp = i_hp;
	m_t_info.i_mp = i_mp;
	m_t_info.i_level = i_level;
	m_t_info.i_exp = i_exp;
}

bool CCharacter::damage(int i_damage)
{
	m_t_info.i_hp -= i_damage;

	return m_t_info.i_hp <= 0;
}

bool CCharacter::add_exp(int i_exp)
{
	m_t_info.i_exp += i_exp;
	return false;
}

void CCharacter::drop_exp()
{
	m_t_info.i_exp *= 0.9f;
}

void CCharacter::full_hp_mp()
{
	m_t_info.i_hp = m_t_info.i_hp_max;
	m_t_info.i_mp = m_t_info.i_mp_max;
}

bool CCharacter::init()
{
	return true;
}

void CCharacter::render()
{
}

#include "monster.h"

CMonster::CMonster()
{
	m_e_type = OT_MONSTER;
}

CMonster::CMonster(const CMonster &monster)	:
	CCharacter(monster)
{
	m_i_gold_min = monster.m_i_gold_min;
	m_i_gold_max = monster.m_i_gold_max;
}

CMonster::~CMonster()
{
}

bool CMonster::init()
{
	return true;
}

void CMonster::render()
{

	cout << "이름 : " << m_str_name << "\t직업 : " << m_str_job_name << '\n';
	cout << "레벨 : " << m_t_info.i_level << "\t획경험치 : " << m_t_info.i_exp << '\n';
	cout << "공격력 : " << m_t_info.i_at_min << " ~ " << m_t_info.i_at_max << "\t방어력 : " 
		<< m_t_info.i_ar_min << " ~ " << m_t_info.i_ar_max << '\n';
	cout << "체력 : " << m_t_info.i_hp << " / " << m_t_info.i_hp_max << "\t마나 : " << m_t_info.i_mp << " / " << m_t_info.i_mp_max;
	cout << "획득가능금액 : " << m_i_gold << " Gold" << '\n';
}

CMonster *CMonster::clone()
{
	return new CMonster(*this);
}

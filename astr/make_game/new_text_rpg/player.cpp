#include "player.h"
#include "item_weapon.h"
#include "item_armor.h"

CPlayer::CPlayer()
{
	m_e_type = OT_PLAYER;
	memset(m_p_equip, 0, sizeof(CItem *) * EQ_END);
}

CPlayer::CPlayer(const CPlayer &player)	:
	CCharacter(player)
{
	m_e_job = player.m_e_job;
	m_str_job_name = player.m_str_job_name;
	m_i_gold = player.m_i_gold;
	memset(m_p_equip, 0, sizeof(CItem *) * EQ_END);
}
CPlayer::~CPlayer()
{
	for (int idx = 0; idx < EQ_END; ++idx)
		SAFE_DELETE(m_p_equip[idx]);
}

void CPlayer::add_gold(int i_gold)
{
	m_i_gold += i_gold;
}

void CPlayer::drop_gold()
{
	m_i_gold *= 0.9f;
}

CItem* CPlayer::equip(CItem *p_item)
{
	EQUIP eq;
	switch (p_item->get_item_info().e_type)
	{
		case IT_WEAPON:
			eq = EQ_WEAPON;
			break ;
		case IT_ARMOR:
			eq = EQ_ARMOR;
			break ;
	}
	if (m_p_equip[eq])
	{
		CItem* p_equip = m_p_equip[eq];
		m_p_equip[eq] = p_item;
		return p_equip;
	}
	m_p_equip[eq] = p_item;
	return NULL;
}

bool CPlayer::init()
{
	cout << "이름을 입력하세요 : ";
	char	str_name[32] = {};
	cin.getline(str_name, 31);
	set_name(str_name);
	int i_job;

	while (true)
	{
		system("cls");
		cout << "1. 기사" << '\n';
		cout << "2. 궁수" << '\n';
		cout << "3. 마법사" << '\n';
		cout << "직업을 선택하세요 : ";
		break;
	}
	m_e_job = (JOB)i_job;
	switch (m_e_job)
	{
		case JOB_KNIGHT:
			m_str_job_name = "knight";
			set_character_info(10, 15, 15, 20, 500, 100, 1, 0);
			break;
		case JOB_ARCHER:
			m_str_job_name = "archer";
			set_character_info(15, 20, 10, 15, 400, 200, 1, 0);
		case JOB_MAGICION:
			m_str_job_name = "magician";
			set_character_info(20, 25, 5, 10, 300, 300, 1, 0);
			break;
	}
}
void CPlayer::render()
{
	cout << "이름 : " << m_str_name << "\t직업 : " << m_str_job_name << '\n';
	cout << "레벨 : " << m_t_info.i_level << "\t경험치 : " << m_t_info.i_exp << '\n';
	cout << "공격력 : ";
	if (m_p_equip[EQ_WEAPON])
	{
		cout << m_t_info.i_at_min << " + " << ((CItemWeapon *)m_p_equip[EQ_WEAPON])->get_attack_min << " ~ " << ((CItemWeapon *)m_p_equip[EQ_WEAPON])->get_attack_max;
	}
	else
	{
   		cout << m_t_info.i_at_min << " ~ " << m_t_info.i_at_max;
	}
   	cout << "\t방어력 : ";
	if (m_p_equip[EQ_ARMOR])
	{
		cout << m_t_info.i_armor_min << " + " << ((CItemArmor *)m_p_equip[EQ_ARMOR])->get_attack_min << " ~ " << ((CItemArmor *)m_p_equip[EQ_ARMOR])->get_armor_max << '\n';
	}
	else
	{
		cout << m_t_info.i_armor_min << " ~ " << m_t_info.i_armor_max << '\n';
	}
	cout << "체력 : " << m_t_info.i_hp << " / " << m_t_info.i_hp_max << "\t마나 : " << m_t_info.i_mp << " / " << m_t_info.i_mp_max;
	cout << "보유금액 : " << m_i_gold << " Gold" << '\n';
	cout << "장착무기 : ";
	if (m_p_equip[EQ_WEAPON])
		cout << m_p_equip[EQ_WEAPON]->get_name();
	else
		cout << "없음";
	cout << "\t장착방어구: ";
	if (m_p_equip[EQ_ARMOR])
		cout << m_p_equip[EQ_ARMOR]->get_name() << '\n';
	else
		cout << "없음" << '\n';
}

CPlayer *CPlayer::clone()
{
	return new CPlayer(*this):
}

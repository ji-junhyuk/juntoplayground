#include "stage.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

void CStage::output_stage_name(char *p_name)
{
	cout << "==================" << p_name << "==================" << '\n';
}

int CStage::output_menu()
{
	cout << "1. 공격" << '\n';
	cout << "2. 뒤로가기" << '\n';
	int i_menu = input<int>();
	if (i_menu <= MENU_NONE || i_menu > MENU_BACK)
		return MENU_NONE;
	return i_menu;
}

CStage::BATTLE_FLAG CStage::battle_attack(CPlayer *p_player, CMonster *p_monster)
{
	int i_damage = p_player->get_damage() - p_monster->get_armor();
	i_damage = i_damage < 1 ? 1 : i_damage;

	cout << p_player->get_name() << " 가 " << p_monster->get_name() << " 에게 " << i_damage << " 피해를 주었습니다." << '\n';

	if (p_monster->damage(i_damage))
		return BF_MONSTER_DIE;
	return BF_NONE;
}

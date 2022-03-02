#include "stage_hard.h"
#include "object_manager.h"
#include "player.h"
#include "monster.h"

CStageHard::CStageHard()
{
}

CStageHard::~CStageHard()
{
}

bool CStageHard::init()
{
	return true;
}

void CStageHard::run()
{
	CPlayer *p_player = (CPlayer *)GET_SINGLE(CObjectManager)->find_object("player");
	CMonster *p_monster = (CMonster *)GET_SINGLE(CObjectManager)->clone_object("dragon");
	while (true)
	{
		system("cls");
		output_stage_name("Hard");
		p_player->render();
		cout << '\n';
		p_monster->render();
		cout << '\n';
		switch (output_menu())
		{
			case MENU_ATTACK:
				switch (battle_attack(p_player, p_monster))
				{
					case BF_PLAYER_DIE:
						p_player->drop_exp();
						p_player->drop_gold();
						p_player->full_hp_mp();
						break;
					case BF_MONSTER_DIE:
						cout << p_player->get_name() << " 이 " << p_monster->get_character_info().i_exp << " 경험치를 회득하였습니다." << '\n';
						int i_drop_gold;
						i_drop_gold = p_monster->get_drop_gold();
						cout << p_player->get_name() << " 이 " << i_drop_gold << " Gold를 획득하였습니다." << '\n';
						p_player->add_exp(p_monster->get_character_info().i_exp);
						p_player->add_gold(i_drop_gold);
						if (p_player->check_level_up())
						{
						}
						SAFE_DELETE(p_monster);
						p_monster = (CMonster *)GET_SINGLE(CObjectManager)->clone_object("dragon");
						break;
				}
				break;
			case MENU_BACK:
				SAFE_DELETE(p_monster);
				return;
		}
		system("pause");
	}
}

#pragma once

#include "value.h"
#include "player.h"
#include "monster.h"

class CStage
{
	public:
		CStage();
		virtual ~CStage();
	protected:
		enum MENU
		{
			MENU_NONE,
			MENU_ATTACK,
			MENU_BACK
		};
		enum BATTLE_FLAG
		{
			BF_NONE,
			BF_PLAYER_DIE,
			BF_MONSTER_DIE
		};
	public:
		virtual bool init() = 0;
		virtual void run() = 0;
	protected:
		void output_stage_name(char *p_name);
		int output_menu();
		BATTLE_FLAG battle_attack(class CPlayer *p_player, class CMonster *p_monster);
};

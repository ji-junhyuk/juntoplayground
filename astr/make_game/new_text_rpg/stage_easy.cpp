#include "stage_easy.h"
#include "object_manger.h"
#include "player.h"
#include "monster.h"

CStageEasy::CStageEasy()
{
}

CStageEasy::~CStageEasy()
{
}

bool CStageEasy::init()
{
	return true;
}

void CStageEasy::run()
{
	CPlayer *p_player = (CPlayer *)GET_SINGLE(CObjectManager)->find_object("player");
	CMonster *p_monster = (CMonster *)GET_SINGLE(CObjectManager)->clone_object("goblin");
	p_player->render();
	p_monster->render();
	SAFE_DELETE(p_monster);
	system("pause");
}

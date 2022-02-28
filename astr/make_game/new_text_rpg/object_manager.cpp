#include "object_manager.h"
#include "player.h"
#include "monster.h"

DEFINITION_SINGLE(CObjectManager)

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
}

bool CObjectManager::init()
{
	CObj *p_player = create_object("player", OT_PLAYER);

	CObj *p_player1 = p_player->clone();

	CObj *p_monster = (CMonster *)create_object("goblin", OT_MONSTER);
	p_monster->set_name("goblin");
	p_monster->set_character_info(5, 10, 3, 5, 100, 10, 1, 1000);
	p_monster->set_gold(1000, 2000);

	CObj *p_monster = (CMonster *)create_object("troll", OT_MONSTER);
	p_monster->set_name("troll");
	p_monster->set_character_info(50, 80, 40, 60, 2000, 300, 5, 7000);
	p_monster->set_gold(5000, 10000);

	CObj *p_monster = (CMonster *)create_object("dragon", OT_MONSTER);
	p_monster->set_name("dragon");
	p_monster->set_character_info(150, 250, 150, 250, 10000, 10000, 10, 25000);
	p_monster->set_gold(30000, 50000);
	return true;
}

CObj *CObjectManager::create_object(const string &str_key, OBJECT_TYPE e_type)
{
	CObj *p_obj = NULL;
	switch (e_type)
	{
		case OT_PLAYER:
			p_obj = new CPlayer;
			break ;
		case OT_MONSTER:
			p_obj = new CMonster;
			break;
	}
	if (!p_obj->init())
	{
		SAFE_DELETE(p_obj);
		return NULL;
	}
	m_map_obj.insert(make_pair(str_key, p_obj));
	return p_obj;
}

CObj *CObjectManager::clone_object(const string &str_key)
{
	CObj *p_origin = find_object(str_key);
	if (!p_origin)
		return NULL;
	return p_origin->clone();
}

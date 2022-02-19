#include "object_manager.h"
#include "player.h"

ObjectManager *ObjectManager::m_p_inst = NULL;
ObjectManager::ObjectManager()	:
	m_p_player(NULL)
{
}

ObjectManager::~ObjectManager()
{
	safe_delete(m_p_player);
}

bool ObjectManager::init()
{
	m_p_player = new CPlayer;
	m_p_player->init();
	return true;
}

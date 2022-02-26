#include "object_manager.h"
#include "player.h"
#include "bullet.h"

ObjectManager *ObjectManager::m_p_inst = NULL;
ObjectManager::ObjectManager()	:
	m_p_player(NULL)
{
}

ObjectManager::~ObjectManager()
{
	safe_delete(m_p_player);
	for (int idx =0; idx < m_i_cur_bullet_count; ++idx)
		safe_delete(m_p_bullet[idx]);
}

bool ObjectManager::init()
{
	m_p_player = new CPlayer;
	m_p_player->init();
	memset(m_p_bullet, 0, sizeof(CBullet *) * BULLET_COUNT_MAX);
	m_i_cur_bullet_count = 0;
	return true;
}

void ObjectManager::update()
{
	m_p_player->update();
	for (int idx = 0; idx < m_i_cur_bullet_count; ++idx)
	{
		m_p_bullet[idx]->update();
	}
	for (int idx = 0; idx < m_i_cur_bullet_count;)
	{
		if (!m_p_bullet[idx]->get_enable())
		{
			delete m_p_bullet[idx];
			for (int jdx = idx; jdx < m_i_cur_bullet_count - 1; ++jdx)
			{
				m_p_bullet[jdx] = m_p_bullet[jdx + 1];
			}
			m_p_bullet[m_i_cur_bullet_count - 1] = NULL;
			--m_i_cur_bullet_count;
		}
		else
			++idx;
	}
}

bool ObjectManager::create_bullet(POINT t_pos)
{
	if (m_i_cur_bullet_count == BULLET_COUNT_MAX)
		return false;
	CBullet *p_bullet = new CBullet;
	if (!p_bullet->init())
	{
		safe_delete(p_bullet);
		return false;
	}
	p_bullet->set_pos(t_pos.x, t_pos.y);
	m_p_bullet[m_i_cur_bullet_count] = p_bullet;
	++m_i_cur_bullet_count;
	return true;
}

bool ObjectManager::check_bullet(int x, int y)
{
	for (int idx = 0; idx < m_i_cur_bullet_count; ++idx)
	{
		if (m_p_bullet[idx]->get_pos().x == x && m_p_bullet[idx]->get_pos().y == y)
			return true;
	}
	return false;
}

#include "stage.h"
#include "file_stream.h"
#include "player.h"
#include "object_manager.h"
#include "monster.h"

CStage::CStage() :
	m_p_monster_array(NULL),
	m_i_monster_count(0),
	m_i_monster_array_count(0)
{
}

CStage::~CStage()
{
	for (int idx = 0; idx < m_i_monster_count; ++idx)
		safe_delete(m_p_monster_array[idx]);
	delete[] m_p_monster_array;
}

bool CStage::init()
{
	return true;
}

bool CStage::init(char *p_file_name)
{
	CFileStream file;
	if (!file.open(p_file_name, "rt"))
		return false;
	for (int idx = 0; idx < 10; ++idx)
	{
		int i_size = 0;
		file.read_line(m_c_origin_stage[idx], i_size);
		for (int jdx = 0; jdx < 50; ++jdx)
		{
			m_c_stage[idx][jdx] = m_c_origin_stage[idx][jdx];
			if (m_c_origin_stage[idx][jdx] == SBT_START)
			{
				m_t_start.x = jdx;
				m_t_start.y = idx;
			}
			else if (m_c_origin_stage[idx][jdx] == SBT_END)
			{
				m_t_end.x = jdx;
				m_t_end.y = idx;
			}
			else if (m_c_origin_stage[idx][jdx] == SBT_MONSTER)
			{
				create_monster(jdx, idx);
				m_c_stage[idx][jdx] = SBT_ROAD;
			}
		}
	}
	return true;
}

void CStage::update()
{
	for (int idx = 0; idx < m_i_monster_array_count; ++idx)
	{
		m_p_monster_array[idx]->update();
	}
}

void CStage::render()
{
	CPlayer *p_player = ObjectManager::get_inst()->get_player();
	int i_x = p_player->get_x();
	int i_y = p_player->get_y();

	int i_y_count = i_y + (RENDER_BLOCK_Y / 2);
	if (i_y_count >= BLOCK_Y)
		i_y_count = BLOCK_Y - 1;

	int i_y_min = i_y_count - (RENDER_BLOCK_Y - 1);
	if (i_y_min < 0)
		i_y_min = 0;

	int i_x_count = i_x + RENDER_BLOCK_X;
	if (i_x_count > BLOCK_X)
		i_x_count = BLOCK_X;
	int i_x_min = i_x;
	if (i_x_min > BLOCK_X - RENDER_BLOCK_X)
		i_x_min = BLOCK_X - RENDER_BLOCK_X;

	for (int idx = i_y_min; idx <= i_y_count; ++idx)
	{
		for (int jdx = i_x_min; jdx < i_x_count; ++jdx)
		{
			if ((idx == i_y || (idx == i_y - 1 && p_player->get_big_item_enable())) && jdx == i_x)
				cout << "㉾";
			else if (ObjectManager::get_inst()->check_bullet(jdx, idx))
				cout << "A";
			else if (check_monster(jdx, idx))
				cout << "M";
			else if (m_c_stage[idx][jdx] == SBT_WALL)
				cout << "■";
			else if (m_c_stage[idx][jdx] == SBT_ROAD)
				cout << " ";
			else if (m_c_stage[idx][jdx] == SBT_START)
				cout << "◐";
			else if (m_c_stage[idx][jdx] == SBT_END)
				cout << "◑";
			else if (m_c_stage[idx][jdx] == SBT_COIN)
				cout << "@";
			else if (m_c_stage[idx][jdx] == SBT_ITEM_BULLET)
				cout << "♠";
			else if (m_c_stage[idx][jdx] == SBT_ITEM_BIG)
				cout << "B";
		}
		cout << '\n';
	}
}

void CStage::reset_stage()
{
	for (int idx = 0; idx < m_i_monster_count; ++idx)
	{
		safe_delete(m_p_monster_array[idx]);
	}
	m_i_monster_count = 0;
	for (int idx = 0; idx < BLOCK_Y; ++idx)
	{
		for (int jdx = 0; jdx < BLOCK_X; ++jdx)
		{
			m_c_stage[idx][jdx] = m_c_origin_stage[idx][jdx];
			if (m_c_origin_stage[idx][jdx] == SBT_MONSTER)
			{
				create_monster(jdx, idx);
				m_c_stage[idx][jdx] = SBT_ROAD;
			}
		}
	}
}

CMonster *CStage::create_monster(int x, int y)
{
	if (!m_p_monster_array)
	{
		m_i_monster_array_count = 2;
		m_p_monster_array = new CMonster *[m_i_monster_array_count];
	}
	if (m_i_monster_count == m_i_monster_array_count)
	{
		m_i_monster_array_count *= 2;
		CMonster **p_p_array = new CMonster *[m_i_monster_array_count];
		memcpy(p_p_array, m_p_monster_array, sizeof(CMonster *) * m_i_monster_count);
		delete[] m_p_monster_array;
		m_p_monster_array = p_p_array;
	}
	CMonster *p_monster = new CMonster;
	if (!p_monster->init())
	{
		safe_delete(p_monster);
		return NULL;
	}
	p_monster->set_pos(x, y);
	m_p_monster_array[m_i_monster_count] = p_monster;
	++m_i_monster_count;
	return p_monster;
}

bool CStage::check_monster(int x, int y)
{
	for (int idx = 0; idx < m_i_monster_count; ++idx)
	{
		if (m_p_monster_array[idx]->get_pos().x == x &&
				m_p_monster_array[idx]->get_pos().y == y)
			return true;
	}
	return false;
}



























#include "stage.h"
#include "file_stream.h"
#include "player.h"
#include "object_manager.h"

CStage::CStage()
{
}

CStage::~CStage()
{
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
		}
	}
	return true;
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
			if (idx == i_y && jdx == i_x)
				cout << "㉾";
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
		}
		cout << '\n';
	}
}

void CStage::reset_stage()
{
	for (int idx = 0; idx < BLOCK_Y; ++idx)
	{
		for (int jdx = 0; jdx < BLOCK_X; ++jdx)
		{
			m_c_stage[idx][jdx] = m_c_origin_stage[idx][jdx];
		}
	}
}

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
		file.read_line(m_c_stage[idx], i_size);
		for (int jdx = 0; jdx < 50; ++jdx)
		{
			if (m_c_stage[idx][jdx] == SBT_START)
			{
				m_t_start.x = jdx;
				m_t_start.y = idx;
			}
			else if (m_c_stage[idx][jdx] == SBT_END)
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

	for (int idx = i_y - 2; idx <= i_y + 1; ++idx)
	{
		for (int jdx = i_x; jdx < i_x + 10; ++jdx)
		{
			if (idx == i_y && jdx == i_x)
				cout << "㉾";
			else if (m_c_stage[idx][jdx] == SBT_WALL)
				cout << "■";
			else if (m_c_stage[idx][jdx] == SBT_ROAD)
				cout << "  ";
			else if (m_c_stage[idx][jdx] == SBT_COIN)
				cout << "@";
		}
		cout << '\n';
	}
}

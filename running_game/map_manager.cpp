#include "map_manager.h"
#include "stage.h"
#include "player.h"
#include "object_manager.h"

CMapManager * CMapManager::m_p_inst = NULL;

CMapManager::CMapManager()
{
	for (int idx = 0; idx < STAGE_MAX_COUNT; ++idx)
	{
		m_p_stage[idx] = NULL;
	}
}

CMapManager::~CMapManager()
{
	for (int idx = 0; idx < STAGE_MAX_COUNT; ++idx)
	{
		safe_delete(m_p_stage[idx]);
	}
}

CMapManager *CMapManager::get_inst()
{
	if (!m_p_inst)
		m_p_inst = new CMapManager;
	return m_p_inst;
}

void CMapManager::destroy_inst()
{
	safe_delete(m_p_inst);
}

bool CMapManager::init()
{
	char *p_stage_file[3] = {"stage1.txt", "stage2.txt", "stage3.txt"};
	for (int idx = 0; idx < STAGE_MAX_COUNT; ++idx)
	{
		m_p_stage[idx] = new CStage;
		if (!m_p_stage[idx]->init(p_stage_file[idx]))
			return false;
	}
	return true;
}

void CMapManager::run(int i_stage)
{
	CPlayer *p_player = ObjectManager::get_inst()->get_player();
	m_i_enable_stage = i_stage;
	m_p_stage[i_stage]->reset_stage();
	p_player->set_pos(m_p_stage[i_stage]->get_start().x, m_p_stage[i_stage]->get_start().y);
	while (true)
	{
		system("cls");
		if (GetAsyncKeyState('Q') & 0x8000)
			break;
		p_player->update();
		m_p_stage[i_stage]->render();
		cout << "Score : " << p_player->get_score() << '\n';
		if (p_player->get_complete())
		{
			cout << "완료" << '\n';
			p_player->reset();
			break;
		}
		Sleep(100);
	}
}

void CMapManager::render()
{
	m_p_stage[0]->render();
}

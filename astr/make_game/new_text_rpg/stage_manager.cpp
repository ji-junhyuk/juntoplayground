#include "stage_manager.h"
#include "stage_easy.h"
#include "stage_normal.h"
#include "stage_hard.h"

DEFINITION_SINGLE(CStageManager)

CStageManager::CStageManager()
{
}

CStageManager::~CStageManager()
{
	safe_delete_vec_list(m_vec_stage);
}

bool CStageManager::init()
{
	if (!create_stage(STR_EASY))
		return false;
	if (!create_stage(STR_NORMAL))
		return false;
	if (!create_stage(STR_HARD))
		return false;
	return true;
}

void CStageManager::run()
{
	while (true)
	{
		int i_menu = output_menu();
		if (i_menu == MENU_NONE)
			continue;
		else if (i_menu == MENU_BACK)
			return;
		m_vec_stage[i_menu - 1]->run();
	}
}

bool CStageManager::create_stage(STAGE_TYPE e_type)
{
	CStage *p_stage = NULL;
	switch (e_type)
	{
		case STR_EASY:
			p_stage = new CStageEasy;
			break;
		case STR_NORMAL:
			p_stage = new CStageNormal;
			break;
		case STR_HARD:
			p_stage = new CStageHard;
			break;
	}
	if (!p_stage->init())
	{
		SAFE_DELETE(p_stage);
		return false;
	}
	m_vec_stage.push_back(p_stage);
	return true;
}

int CStageManager::output_menu()
{
	system("cls");
	cout << "1. 쉬움" << '\n';
	cout << "2. 보통" << '\n';
	cout << "3. 어려움" << '\n';
	cout << "4. 뒤로가기" << '\n';
	int i_menu = input<int>();
	if (i_menu <= MENU_NONE || i_menu > MENU_BACK)
		return MENU_NONE;
	return i_menu;
}

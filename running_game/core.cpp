#include "core.h"
#include "map_manager.h"
#include "object_manager.h"
#include "player.h"

CCore *CCore::m_p_inst = NULL;

CCore::CCore()
{
	srand((unsigned int)time(0));
}

CCore::~CCore()
{
	CMapManager::destroy_inst();
	ObjectManager::destroy_inst();
}

CCore *CCore::get_inst()
{
	if (!m_p_inst)
		m_p_inst = new CCore;
	return m_p_inst;
}

void CCore::destroy_inst()
{
	safe_delete(m_p_inst);
}

bool CCore::init()
{
	if (!CMapManager::get_inst()->init())
		return false;
	if (!ObjectManager::get_inst()->init())
		return false;
	return true;
}

void CCore::run()
{
	while (true)
	{
		int i_stage = output_menu();
		if (i_stage == 4)
			break ;
		else if (i_stage == 0)
			continue ;
		system("cls");
		CMapManager::get_inst()->run(i_stage - 1);
	}
}

int CCore::output_menu()
{
	system("cls");
	cout << "1. Stage1" << '\n';
	cout << "2. Stage2" << '\n';
	cout << "3. Stage3" << '\n';
	cout << "4. exit" << '\n';
	cout << "Input Stage : ";
	int i_input = get_input();
	if (i_input < 1 || i_input > 4)
		return (0);
	return i_input;
}

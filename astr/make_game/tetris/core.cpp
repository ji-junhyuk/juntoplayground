#include "core.h"
#include "stage_manager.h"
#include "shape_manager.h"

CCore *CCore::m_p_inst = NULL;

CCore::CCore()
{
	srand((unsigned int)time(0));
}

CCore::~CCore()
{
	CShapeManager::destroy_inst();
	CStageManager::destroy_inst();
}

bool CCore::init()
{
	m_h_console = get_std_hanle(STD_OUTPUT_HANDLE);
	if (m_h_console == INVALID_HANDLE_VALUE)
		return false;
	if (!CStageManager::get_inst()->init())
		return false;
	return true;
}

void CCore::run()
{
	while (true)
	{
		system("cls");
		CShapeManager::get_inst()->update();
		CStageManager::get_inst()->run();
		CShapeManager::get_inst()->render();
		sleep(1000);
	}
}

void CCore::set_console_pos(int x, int y)
{
	COORD	pos = {x * 2, y};
	SetConsoleCursorPosition(m_h_console, pos);
	return 0;
}

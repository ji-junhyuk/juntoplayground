#include "Core.h"
#include "StageManager.h"
#include "ShapeManager.h"

Core* Core::m_pInst = NULL;

Core::Core()	:
	m_bLoop(true)
{
	srand((unsigned int)time(0));
}

Core::~Core()
{
	StageManager::DestroyInst();
	ShapeManager::DestroyInst();
}

bool Core::Init()
{
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;

	if (!StageManager::GetInst()->Init())
		return false;

	return true;
}

void Core::Run()
{
	while (m_bLoop)
	{
		system("cls");
		ShapeManager::GetInst()->Update();
		StageManager::GetInst()->Run();
		ShapeManager::GetInst()->Render();
		Sleep(100);
	}
}

void Core::SetConsolePos(short x, short y)
{
	COORD pos = { (x + 1) * 2, y };
	SetConsoleCursorPosition(m_hConsole, pos);
}

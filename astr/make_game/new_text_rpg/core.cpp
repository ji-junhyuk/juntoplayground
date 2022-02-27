#include "core.h"

DEFINITION_SINGLE(CCore)

enum MAIN_MENU
{
	MM_NONE,
	MM_STAGE,
	MM_STORE,
	MM_INVENTORY,
	MM_STATUS,
	MM_EXIT
};

CCore::CCore()
{
}

CCore::~CCore()
{
}

bool CCore::init()
{
	return true;
}

void CCore::run()
{
	while (true)
	{
		switch (output_menu())
		{
			case MM_STAGE:
				break;
			case MM_STORE:
				break;
			case MM_INVENTORY:
				break;
			case MM_STATUS:
				break;
			case MM_EXIT:
				return; 
		}
	}
}

int CCore::output_menu()
{
	system("cls");
	cout << "1. 맵" << '\n';
	cout << "2. 상점" << '\n';
	cout << "3. 인벤토리" << '\n';
	cout << "4. 케릭터정보" << '\n';
	cout << "5. 종료" << '\n';
	cout << "메뉴를 선택하세요 : ";
	int i_menu = input<int>();
	if (i_menu <= MM_NONE || i_menu > MM_EXIT)
		return MM_NONE;
	return i_menu;
}

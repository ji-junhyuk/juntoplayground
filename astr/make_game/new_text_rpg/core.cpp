#include "core.h"
#include "stage_manager.h"
#include "object_manager.h"
#include "store_manager.h"
#include "inventory.h"

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
	DESTROY_SINGLE(CInventory);
	DESTROY_SINGLE(CObjectManager);
	DESTROY_SINGLE(CStageManager);
	DESTROY_SINGLE(CStoreManager);
}

bool CCore::init()
{
	if (!GET_SINGLE(CObjectManager)->init())
		return false;
	if (!GET_SINGLE(CStageManager)->init())
		return false;
	if (!GET_SINGLE(CStoreManager)->init())
		return false;
	if (!GET_SINGLE(CInventory)->init())
		return false;
	return true;
}

void CCore::run()
{
	while (true)
	{
		switch (output_menu())
		{
			case MM_STAGE:
				GET_SINGLE(CStageManager)->run();
				break;
			case MM_STORE:
				GET_SINGLE(CStoreManager)->run();
				break;
			case MM_INVENTORY:
				GET_SINGLE(CInventory)->run();
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
